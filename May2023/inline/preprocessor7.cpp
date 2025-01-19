#include "system.h"
#include <cstdio>
#include <math.h>  //for sqrt()

/*
this file demostrates usage of multiline macros
some sort of scripts which you should be very careful with 

*/
     

#define TRIANGLE_AREA(a, b)  ((a) * (b))/2    //you can't leave out a cpace in declaration

#define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__  //__VA_ARGS__ is just a coma 
                                                     //separated list, nothing more

#define Y(...) {__VA_ARGS__}

#define Z(...) #__VA_ARGS__   //arguments as one string

#define TO_STRING(...) #__VA_ARGS__
#define STR(x) #x

#define PRINT_IT_VAL(x) printf("%s = %d\n", #x, x);  //This one is an actuall function
//void functions can be replced by macros..
#define substitutionFunction(x) printf("substitution function value is %d\n", x);

#define maxFunction(a, b) a>b? a:b   //this behaves like a real function

//except the fact that they don't return
#define PRINT_NUMS_TO_PRODUCTS(a, b)  do{   \ 
        int product = (a) * (b);            \
        for(int i=0; i<product; i++){       \
            printf("%d\n", i);              \
        }                                   \
    }while(0) 

#define someMacro(x, y) {(x)+(x);}     //refuses to work error: expression is not assignable
#define someMacro(x, y) {x++;}     //refuses to work error: expression is not assignable
                                   //doesn't compile, compilation error, not preprocessoer 

#define anotherMACRO(a, b)     do{                           \
    const char* string0 = a;                                 \
    puts(string0);      /*we can print things*/              \   
    while(*string0 != '\0'){                                 \   
        printf("%c ", *string0);                             \
        string0++;                                           \
    }                                                        \   
}while(0)
//you can not break a macro with //comment lines!!
#define ASD
int main(void){
#ifdef __DATE__    //the string value of compilation date
    int secs = 2;
    puts("starting sleep");
    sleep(2);
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
    PRINT_NUMS_TO_PRODUCTS(3, 6);
    //int value = someMacro(5, 9);
    //int value = 5++;   //this is the problem  it's an expression, needs to be
                       //a modifiable lvalue
    anotherMACRO("we can assing things", 987);
    


    return 0;
}