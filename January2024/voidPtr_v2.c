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
    
    printf("this is an address of intA %p\n", &intA);
    b = (float*)a;
    printf("this is an address of intA %p, stored in pointer b\n", b);
    printf("this is the value of  intA %f, pointed by pointer b\n", *b);
    //no warnings during compile time!! but the value is lost
    printf("this is the value of  intA %d, pointed by pointer b\n", *(int*)b); //!!!!
    // casting float pointer to int pointer and then dereferecing, reading right to left
    // just look at this!!!! this fucking works!!
    aa = (int*)b;
    printf("this is an address of intA %p, stored in pointer b\n", b);
    printf("this is the value of  intA %d, pointed by pointer aa\n", *aa); 
    //fucking works!!

    floatB = intA;  //not a warning during writing  IMPLICIT CAST
    printf("this is floatB %f \n", floatB);  // and prints like a charm

    intAA = floatB;  //not a worning, IMPLICIT CAST, floors the float to int
    printf("this is intAA now %d \n", intAA);  
    intAA = floatBB;  //not a worning, IMPLICIT CAST, floors the float to int
    printf("this is intAA now %d \n", intAA);  

    void* vp = &floatBB;
    float* fp = (float*)&intAA;


        return 0;
}