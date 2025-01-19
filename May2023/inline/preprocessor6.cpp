#include "system.h"
#include <cstdio>
#include <math.h>  //for sqrt()

/*
this file demostrates usage of macros with variable number of argunents

*/
     
#define MACRO(x) x * x

#define shit(y)  y + y

#define sqrt(z) (z) * (z)   //for some reason its not enoough

#define SQUARE_ROOT(a) ((a) * (a))  //this is the way to do it
                                    //outer braces are ommited in the result
#define TRIANGLE_AREA(a, b)  ((a) * (b))/2    //you can't leave out a cpace in declaration

#define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__  //__VA_ARGS__ is just a coma 
                                                     //separated list, nothing more

#define Y(...) {__VA_ARGS__}

#define Z(...) #__VA_ARGS__   //arguments as one string

#define TO_STRING(...) #__VA_ARGS__
#define STR(x) #x

#define PRINT_IT_VAL(x) printf("%s = %d\n", #x, x);  //This one is an actuall function

#define substitutionFunction(x) printf("substitution function value is %d\n", x);

#define maxFunction(a, b) a>b? a:b



int main(void){
#ifdef __DATE__    //the string value of compilation date
    int secs = 2;
    puts("starting sleep");
    sleep(2);
    
    printf("this is MACRO %i\n", SQUARE_ROOT(435 + 33));
    printf("this is MACRO %i\n", TRIANGLE_AREA(435 + 33,    348^5));
    //printf("this is MACRO %i\n", TRIANGLE_AREA(435 & ^FUCK YOU,    348^5));  //works
    printf("this is MACRO %i\n", TRIANGLE_AREA(435 / 56,    348^5));  //we can use it
                                    // for constant expressions above the computation
    printf("this is %d %f %s %i\n", X(5, 4, 3.14, "Hi", 12)); 
#endif //__DATE__

    int list[7] = Y(4, 6, 2, 11, 7, 8, 4);    //visually changes the language
    printf("%s\n", Z(3, 56, 54, 67.45, A, 0.7456));
    printf("%s\n", TO_STRING(3, "Wow", 54, 67.45, A, 0.7456));  //works like a charm

    printf("%s\n", STR(848/12 + 35*35));    //this actually is helpfull
    PRINT_IT_VAL(secs);
    substitutionFunction(2524);
    int max = maxFunction(234, 567);   //now I see..
    printf("%d\n", max);


    return 0;
}