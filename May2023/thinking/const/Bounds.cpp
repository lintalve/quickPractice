#include "Bounds.h"

Bounds::Bounds(){
    printf("creating Bounds object\n");
    this->min = Vec3(-5.00f, -5.00f, -5.00f);
    this->max = Vec3(5.00f, 5.00f, 5.00f);
}
Bounds::Bounds(Vec3 min, Vec3 max){
    this->min = min;
    this->max = max;
}
Bounds::Bounds(float min0, float min1, float min2, float max0, float max1, float max2){
    this->min = Vec3(static_cast<double>(min0), static_cast<double>(min1), static_cast<double>(min2));
    this->max = Vec3(static_cast<double>(max0), static_cast<double>(max1), static_cast<double>(max2));
}
Bounds::~Bounds(){
    printf("removing Bounds object\n");
}
const Vec3 Bounds::getMin() const {     //const method CAN'T call non const methods
    return min;                         //even embeded user type object methods
}
Vec3 Bounds::getMax() const {
    return max;
}

void Bounds::setMin(float x, float y, float z){
    min.setX(x);
    min.setY(y);
    min.setZ(z);
}
void Bounds::setMax(float x, float y, float z){
    max.setX(x);
    max.setY(y);
    max.setZ(z);
}
const char* Bounds::toString(){
        return "qwre";
    }
void Bounds::someConstMethod() const{
    //someNonConstMethod();      //can't call it here, it's not const
    printf("trying to call non const method from const method");
}
void Bounds::someOtherConstMethod() const {
    someConstMethod();      //can call it here, it's const
}