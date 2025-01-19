#include "Vec.h"

//////Vec2/////
Vec2::Vec2(){
    data[0] = data[1] = 0;
}
Vec2::Vec2(float x, float y){
    data[0] = static_cast<double>(x);
    data[1] = static_cast<double>(y);

}
Vec2::Vec2(double x, double y){
    data[0] = x;
    data[1] = y;

}

//////Vec3/////
Vec3::Vec3(){
    data[0] = data[1] = data[2] = 0;
}
Vec3::Vec3(float x, float y, float z){
    data[0] = static_cast<double>(x);
    data[1] = static_cast<double>(y);
    data[2] = static_cast<double>(z);
}
Vec3::Vec3(double x, double y, double z){
    data[0] = x;
    data[1] = y;
    data[2] = z;
}
float Vec3::getXf(){
    return static_cast<float>(data[0]);
}
float Vec3::getYf(){
    return static_cast<float>(data[1]);
}
float Vec3::getZf(){
    return static_cast<float>(data[2]);
}
Vec3::~Vec3(){
    printf("removing object of type Vec3\n");
}
double Vec3::getXd() const {
    return data[0];
}
const double Vec3::getYd() const {
    return data[1];
}
double Vec3::getZd() const {
    return data[2];
}

void Vec3::setX(float x){
    data[0] = static_cast<double>(x);
}
void Vec3::setY(float y){
    data[1] = static_cast<double>(y);
}
void Vec3::setZ(float z){
    data[2] = static_cast<double>(z);
}
void Vec3::setX(double x){
    data[0] = x;
}
void Vec3::setY(double y){
    data[1] = y;
}
void Vec3::setZ(double z){
    data[2] = z;
}