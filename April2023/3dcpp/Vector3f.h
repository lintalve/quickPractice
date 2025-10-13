#ifndef VECTOR3F_H
#define	VECTOR3F_H

#include "Vector2f.h"
//#include "position.h"

struct Vector3f{
    float x;
    float y;
    float z;

    Vector3f(float x, float y, float z);
    Vector3f(Vector2f vec, float z);
    Vector3f operator+(const Vector3f&);
    Vector3f add(const Vector3f&);
};
#endif