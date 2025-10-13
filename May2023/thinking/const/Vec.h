#ifndef VEC_H
#define VEC_H
#include <stdio.h>

class Vec2{
    static const int size = 2;
    double data[size];
public:
    double x;
    double y;
    Vec2();
    Vec2(double x, double y);
    Vec2(float x, float y);
    ~Vec2();
};

class Vec3{
    static const int size = 3;
    double data[size];
public:
    double x;
    double y;
    double z;
    Vec3();
    Vec3(double x, double y, double z);
    Vec3(float x, float y, float z);
    ~Vec3();
    float getXf();
    float getYf();
    float getZf();
    double getXd() const;
    const double getYd() const;   //const methods must call const methods only???
    double getZd() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

};

#endif // ends VEC_H