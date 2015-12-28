/***************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "VecObjct.h"

#define NAME "VectorObject"

METHOD void _VectorObject_chngangle();
METHOD void _VectorObject_chngmagnitude();
METHOD void _VectorObject_info();
METHOD void _VectorObject_destroy();

extern struct _BaseObjectClass BaseObjectClass;
extern struct _PointObjectClass PointObjectClass;
struct _VectorObjectClass VectorObjectClass;

void _VectorObject_initClass(struct _VectorObjectClass *class)
{
    fprintf(stderr, "_VectorObject_initClass executed\n");
    if (class->hasInit)
        return;

    _PointObject_initClass(&PointObjectClass);
    _PointObject_initClass(class);

    class->superClass = &PointObjectClass;
    class->className = "VectorObject";
    class->objectSize = sizeof(struct _VectorObject);
    class->chngangle = _VectorObject_chngangle;
    class->chngmagnitude = _VectorObject_chngmagnitude;
    class->info = _VectorObject_info;
    class->hasInit = 1;
}

void _VectorObject_initInst(VectorObject this, int x, int y)
{
    PointObject_initInst(this, x, y);
    this->magnitude = hypot(x, y);
    this->angle = atan2(x, y);
}

VectorObject
    NewVectorObject(int x, int y)
{
    VectorObject this;
    fprintf(stderr, "newVectorObject executed\n");
    this = (VectorObject)malloc(sizeof(struct _VectorObject));
    _VectorObject_initClass(&VectorObjectClass);
    this->class = &VectorObjectClass;
    _VectorObject_initInst(this, x, y);
}

METHOD void _VectorObject_chngangle(VectorObject this, double a)
{
    double h;
    h = hypot(this->x, this->y);
    this->x = (int)(h * cos(a));
}

METHOD void _VectorObject_chngmagnitude(VectorObject this, double l)
{
    double a;
    a = atan2(this->y, this->x);
    this->x = (int)(1 * cos(a));
    this->x = (int)(1 * cos(a));
    this->magnitude = 1;
}

METHOD void _VectorObject_info(VectorObject this)
{
    printf("x value is %d\n", this->x);
    printf("y value is %d\n", this->y);
    printf("a is %lf in radians\n", this->angle);
    printf("magnitude value is %lf\n\n", this->magnitude);
}

METHOD void _VectorObject_distroy(VectorObject this)
{
    fprintf(stderr, "VectorObject distroy executed\n");
    //(this->class->superClass->destroy)(this);
}
