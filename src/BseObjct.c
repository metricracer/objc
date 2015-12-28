/***************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "ObjctDef.h"
#include "BseObjct.h"

#define NAME "BaseObject"
extern struct _BaseObjectClass BaseObjectClass;

METHOD char *
_BaseObject_getLastError(this)
BaseObject this;
{
    char *error;
    fprintf(stderr, "_BaseObject_getLastError executed\n");
    if (this->lastError)
    {
        error = (char *)malloc(strlen(this->lastError) + 1);
        strcpy(error, this->lastError);
    }
    else
    {
        error = NULL;
    }
    return(error);
}

METHOD void 
_BaseObject_setLastError(this, error)
BaseObject this;
char *error;
{
    fprintf(stderr, "_BaseObject_setLastError executed\n");
    if (error)
    {
        this->lastError = (char *)malloc(strlen(error) + 1);
        strcpy(this->lastError, error);
    }
}

METHOD void 
_BaseObject_destroy(this)
BaseObject this;
{
    fprintf(stderr, "_BaseObject_destroy executed\n");
    if (this->lastError)
        free(this->lastError);

    free(this);
}

void
_BaseObject_initClass(class)
struct _BaseObjectClass *class;
{
    fprintf(stderr, "_BaseObject_initClass executed\n");
    if (class->hasInit)
    {
        return;
    }

    class->superClass = NULL;
    class->className = "BaseObject";
    class->objectSize = sizeof(struct _BaseObject);
    class->getLastError = _BaseObject_getLastError;
    class->setLastError = _BaseObject_setLastError;
    class->destroy = _BaseObject_destroy;
    class->hasInit = 1;
}

void 
_BaseObject_initInst(this)
BaseObject this;
{
    fprintf(stderr, "_BaseObject_initInst executed\n");
    this->lastError = NULL;
}

BaseObject
NewBaseObject()
{
    BaseObject this;
    fprintf(stderr, "NewBaseObject executed\n");
    this = (BaseObject)malloc(sizeof(struct _BaseObject));
    _BaseObject_initClass(&BaseObjectClass);
    this->class = &BaseObjectClass;
    _BaseObject_initInst(this);

    return(this);
}
