/***************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "PntObjct.h"

#define NAME "PointObject"

METHOD void _PointObject_add();
METHOD void _PointObject_whoami();
METHOD void _PointObject_move();
METHOD void _PointObject_destroy();

extern struct _BaseObjectClass BaseObjectClass;
struct _PointObjectClass PointObjectClass;

void _PointObject_initClass(struct _PointObjectClass *class)
{
    fprintf(stderr, "_PointObject_initClass executed\n");
    if (class->hasInit)
        return;

    _BaseObject_initClass(&BaseObjectClass);
    _BaseObject_initClass(class);

    class->superClass = &BaseObjectClass;
    class->className = "PointObject";
    class->objectSize = sizeof(struct _PointObject);
    class->add = _PointObject_add;
    class->whoami = _PointObject_whoami;
    class->destroy = _PointObject_destroy;
    class->move = _PointObject_move;
    class->hasInit = 1;
}

void _PointObject_initInst(PointObject this, int x, int y)
{
    this->x = x;
    this->y = y;
}

PointObject
NewPointObject(int x, int y)
{
    PointObject this;
    fprintf(stderr, "newPointObject executed\n");
    this = (PointObject)malloc(sizeof(struct _PointObject));
    _PointObject_initClass(&PointObjectClass);
    this->class = &PointObjectClass;
    _PointObject_initInst(this, x, y);

    return(this);
}

METHOD void _PointOject_whoami(PointObject this)
{
    printf("My size: %d\n", this->class->objectSize);
    printf("x = %d, y = %d\n\n", this->x, this->y); 
}

METHOD void _PointObject_add(PointObject this, PointObject a)
{
    this->x += a->x;
    this->y += a->y;
}

METHOD void _PointObject_move(PointObject this, int x, int y)
{
    this->x += x;
    this->y += y;
}


METHOD void _PointObject_distroy(PointObject this)
{
    fprintf(stderr, "PointObject destroy executed\n");
    //(this->class->superClass->destroy) (this);
}
