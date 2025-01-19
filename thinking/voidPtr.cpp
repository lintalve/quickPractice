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
    printf("this is an address of intA %p, stored in pointer a\n", a);
    printf("this is an address of intAA %p, stored in pointer aa\n\n", aa);
    //! a = b;  // you can't assign pointer to float to a pointer to int
    aa = a;   // but you can assign pointer to int to a pointer to int;
    printf("this is an address of intA %p, stored in pointer a\n", a);
    printf("this is an address of intAA %p, stored in pointer aa\n", aa);
    c = aa;  //it was pointer to void, and now it is apointer to an int;
    printf("this is an address of intA %p, stored in pointer c\n", c);
    a = cc;  //was *int, now *void
    printf("this is an address of ??? %p, stored in pointer a\n", a);
    a = b;
    printf("this is an address of intA %p, stored in pointer a\n", c);
    return 0;
}