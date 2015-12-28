/*******************************************************************/
#ifndef _BseObjcth
#define _BseObjcth

#include <stdio.h>
#include <stdlib.h>
#include "ObjctDef.h"

#ifndef SUPER_STRUCT
#define SUPER_STRUCT void
#endif

#define _BaseObjectClassRec \
    SUPER_STRUCT *superClass; \
    char    *className; \
    unsigned short objectSize; \
    char    (*getLastError) (); \
    void    (*setLastError) (); \
    void    (*destroy) (); \
    unsigned short hasInit

#define _BaseObjectInstRec \
    char    *lastError

struct _BaseObjectClass
{
    _BaseObjectClassRec;
};

struct _BaseObject
{
    struct _BaseObjectClass *class;
    _BaseObjectInstRec;
};

typedef struct _BaseObject *BaseObject;

extern BaseObject NewBaseObject();
extern void _BaseObject_initClass();
extern void _BaseObject_initInst();

#undef SUPER_STRUCT

#endif /* _BseObjcth */
