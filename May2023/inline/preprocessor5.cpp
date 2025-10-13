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

#define TRIANGLE_AREA(a, b)  ((a) * (b))/2    //you can't leave out a cpace in declaration

#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c)))/(2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c)))/(2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

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
    printf("this is TRIANGLE_AREA = %i \n", TRIANGLE_AREA(543, 45));
    //long int k, l = (5, 7);       //tuple assignment doesn't seem to work
    long double p = QUADP(453.0, 458.0, 772.0);
    long double m = QUADM(453.0, 458.0, 772.0);

    printf("so the x = QUAD(a, b, c) = %Lf or %Lf \n", p, m);    //do you lo
    //printf("%ld %ld\n", k, l);
        //I don't get it
#endif //__DATE__

    return 0;
}