/****************************************************/
#include <stdlib.h>
#include "PntObjct.h"
#include "VecObjct.h"
#define PI 3.142857

int main()
{
    VectorObject vec1, vec2;

    vec1 = NewVectorObject(5, 5);
    vec2 = NewVectorObject(10, 5);

    MSG(vec1, info) (vec1);
    MSG(vec1, info) (vec1);
    MSG(vec1, info) (vec1);

    MSG(vec2, info) (vec2);
    MSG(vec2, chngmagnitude) (vec2, 100.0);
    MSG(vec2, info) (vec2);

    return(0);
}
