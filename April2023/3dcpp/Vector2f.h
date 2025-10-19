#ifndef VECTOR2F_H
#define	VECTOR2F_H

struct Vector2f{
    float x;
    float y;

    Vector2f(float x, float y);
    ~Vector2f();
    
    float getX();
    float getY();
};
#endif