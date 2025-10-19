
#include "Vector3f.h"
#include "Vector2f.h"
//#include "position.h"

//CONSTRUCTORS
Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3f::Vector3f(Vector2f vec2, float z) : x(vec2.getX()), y(vec2.getY()), z(z) {}

Vector3f Vector3f::add(const Vector3f& other){
    return Vector3f(x += other.x, y += other.y, z += other.z);
}
//Vector3f Vector3f::operator+(const Vector3f&);  //declaration ooutside its class is forbidden
Vector3f Vector3f::operator+(const Vector3f& other){
    return Vector3f(x += other.x, y += other.y, z += other.z);
}