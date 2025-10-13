#include "system.h"
#include <cstdio>
#include <math.h>  //for sqrt()

/*
this file demostrates usage of macros with argunents
*/
     
#define MACRO(x) x * x

#define shit(y)  y + y

#define sqrt(z) (z) * (z)   //for some reason its not enoough

#define SQUARE_ROOT(a) ((z) * (z))  //this is the way to do it
                                    //outer braces are ommited in the result

#define TRIANGLE_AREA (b)  b + b    //you can't leave out a cpace in definition

int main(void){
#ifdef __DATE__    //the string value of compilation date
    int secs = 2;
    puts("starting sleep");
    sleep(2);
    printf("this is macro %i\n", MACRO(4)); 
    printf("this is shit %i\n", shit(435)); 
    printf("this is MACRO %i\n", MACRO(435 + 33));     //as you can see in pressor.i file
                                                       //the MACRO is textualy substituted
                                                       //to 435 + 33 * 435 + 33 
    printf("this is sqrt(z) = %i\n", sqrt(987 + 33));
    printf("this is SQUARE_ROOT = %i\n", sqrt(987 + 234 - 23));
    printf("this is TRIANGLE_AREA\n", TRIANGLE_AREA(543));
        
#endif //__DATE__

    return 0;
}