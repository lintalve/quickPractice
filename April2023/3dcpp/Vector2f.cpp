#include "Vector2f.h"

//CONSTRUTORS
Vector2f::Vector2f(float x, float y) : x(x), y(y) {}
//DESTRUCTOR
Vector2f::~Vector2f(){};
//METHODS
float Vector2f::getX(){
    return x;
}
float Vector2f::getY(){
    return y;
}


