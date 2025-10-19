#ifndef BOUNDS_H
#define BOUNDS_H
#include "Vec.h"
#include <stdio.h>

class Bounds{
    Vec3 min;
    Vec3 max;
public:
    Bounds();
    Bounds(Vec3 min, Vec3 max);
    Bounds(float min0, float min1, float min2, float max0, float max1, float max2);
    Bounds(double min0, double min1, double min2, double max0, double max1, double max2);
    ~Bounds();

    const Vec3 getMin() const;
    Vec3 getMax() const;
    void setMin(float x, float y, float z);
    void setMax(float x, float y, float z);
    const char* toString();
//////////////////
    void someConstMethod() const;
    void someNonConstMethod();
    void someOtherConstMethod() const;
};

#endif //BOUNDS_H