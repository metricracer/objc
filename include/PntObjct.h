/*******************************************************************/
#ifndef _PntObjcth
#define _PntObjcth

#include <stdio.h>
#include <stdlib.h>
#include "ObjctDef.h"
#include "BseObjct.h"

#ifndef SUPER_STRUCT
#define SUPER_STRUCT struct _BaseObjectClass *
#endif

#define _PointObjectClassRec \
    void (*add) (); \
    void (*whoami) (); \
    void (*move) ()

#define _PointObjectInstRec \
    int x; \
    int y

struct _PointObjectClass
{
    _BaseObjectClassRec;
    _PointObjectClassRec;
};

struct _PointObject
{
    struct _PointObjectClass *class;
    _BaseObjectInstRec;
    _PointObjectInstRec;
};

typedef struct _PointObject *PointObject;

extern PointObject NewPointObject();
extern void _PointObject_initClass();
extern void _PointObject_initInst();

#undef SUPER_STRUCT

#endif /* _PntObjcth */
