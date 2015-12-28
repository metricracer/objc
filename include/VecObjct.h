/*******************************************************/
#ifndef _VecObjcth
#define _VecObjcth

#include <stdio.h>
#include <stdlib.h>
#include "ObjctDef.h"
#include "PntObjct.h"

#ifndef SUPER_STRUCT
#define SUPER_STRUCT struct _PointObjectClass *
#endif

#define _VectorObjectClassRec \
    void (*chngangle) (); \
    void (*info) (); \
    void (*chngmagnitude) ()

#define _VectorObjectInstRec \
    double angle; \
    double magnitude

struct _VectorObjectClass
{
    _BaseObjectClassRec;
    _PointObjectClassRec;
    _VectorObjectClassRec;
};

struct _VectorObject
{
    struct _VectorObjectClass *class;
    _BaseObjectInstRec;
    _PointObjectInstRec;
    _VectorObjectInstRec;            
};

typedef struct _VectorObject * VectorObject;

extern VectorObject NewVectorObject();
extern void _VectorObject_initClass();
extern void _VectorObject_initInst();

#undef SUPER_STRUCT

#endif
