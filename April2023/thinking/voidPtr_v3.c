#include <stdio.h>

int main(void){
    int intA = 3;
    int intAA = 5;
    float floatB = 3.4f;
    float floatBB = 5.5f;


    int* a = &intA;
    int* aa = &intAA;
    float* b = &floatB;
    float* bb = &floatBB;
    void* c;
    void* cc;
     

    void* vp = &floatBB;
    float* fp = &intAA;   //c style casting, weird, should be forbidden
                          // gives a warning with clang  
    printf("this is an address of intAA %p\n", &intAA);
    printf("this is the address of intAA %p, assign to a float pointer fp\n", fp);
    fp = (float*)&intAA;   //more c++ style casting
                           //in c++ you must cast before assigning to a pointer to]
                           //a different type 
    printf("this is an address of floatBB %p, stored in void pointer vp\n", vp);
    printf("this is an address of intAA %p\n", &intAA);
    printf("this is an address of intAA %p, converted and then\
 stored in float pointer fp\n", fp);

        return 0;
}