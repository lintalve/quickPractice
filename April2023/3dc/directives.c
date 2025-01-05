#include <math.h>
#include <stdio.h>
#include "attribute.h"
// let's say we are writing a program to compute something
//using macros could act as an input values for computation
#define SOME_SHIT
#define SOME_VALUE 234     //you don't add semicolon after preprocessor directives

struct Point{
    int ID;
    float x;
    float y;
    attr a;    // okay, so you can make a struct inside another struct
};




void main(void){

#ifdef SOME_SHIT
    const char* someString = "Motherfucker, you fucking asshole";
    //that above is the string without importing a string;
    //it is constant because all that can't change should
    //be tagged as const
    //besides that this data is immutable(from python)
    printf("some okward shit\n");
#endif

    struct Point point;     // struct Point, not just point

#ifdef SOME_SHIT
    point.x = 123.324f;
#endif

}