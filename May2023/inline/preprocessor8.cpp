#include "system.h"
#include <cstdio>
#include <math.h>  //for sqrt()
#include "assert.h"

/*
this file demostrates usage of multiline macros
some sort of scripts which you should be very careful with 

*/
     

#define PRINT_NUMS_TO_PRODUCTS(a, b) \
    do{\ 
        int product = (a) * (b);            \
        for(int i=0; i<product; i++){       \
            printf("%d\n", i);              \
        }                                   \
    }while(0) 
//////////////////////////////////////////////////////////////
#define anotherMACRO(a, b)    \
 do{\
    const char* string0 = a;\
    puts(string0); \   
    while(*string0 != '\0'){                                 \   
        printf("%c ", *string0);                             \
        string0++;                                           \
    }                                                        \   
}while(0)
//you can not break a macro with //comment lines!!
////////////////////////////ASSERT_MACRO////////////////////////////////////////
#if ASSERT_ENABLED
#define ASSERT(a, b)    \
do{                     \
    if(!(a)){           \
        fprintf(stderr, __FILE__":%d: %s %s\n", __LINE__, #a, b);  \
        exit(1);        \
    }                   \
}while(0)
#else ASSERT(a, b)      //empty macro
#endif
/////////////////////////////////////////////////////////////////
int main(void){

    PRINT_NUMS_TO_PRODUCTS(3, 6);
    //int value = someMacro(5, 9);
    //int value = 5++;   //this is the problem  it's an expression, needs to be
                       //a modifiable lvalue
    anotherMACRO("we can assing things", 987);
    int x = 30;
    ASSERT(x<20, "assertion failed");
    return 0;
}