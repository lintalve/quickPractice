#include <math.h>
#include <stdio.h>
//#include "attribute.h"
#include "Vector3f.h"
// let's say we are writing a program to compute something
//using macros could act as an input values for computation
#define SOME_SHIT
#define SOME_VALUE 234     //you don't add semicolon after preprocessor directives

struct Point{
    int ID;
    float x;
    float y;
    //attr a;    // okay, so you can make a struct inside another struct
};




int main(void){

#ifdef SOME_SHIT
    //char* someString = "Motherfucker, you fucking asshole";
    //that above is the string without importing a string;
    printf("some okward shit\n");
#endif

    struct Point point;     // struct Point, not just point

#ifdef SOME_SHIT
    point.x = 123.324f;
#endif

    Vector3f vec1 = Vector3f(2.5f, 4.6f, 7.3f);
    Vector3f vec2 = Vector3f(1.5f, 3.6f, 5.3f);

    Vector3f vec3 = vec1 + vec2;

    printf("vec3(%.1f, %.1f, %.1f) result is vec1(%.1f, %.1f, %.1f) + vec2(%.1f, %.1f, %.1f)", 
            vec3.x, vec3.y, vec3.z, vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
    return 0;
}