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
    //! a = b;  // you can't assign pointer to float to a pointer to int directly
    aa = a;   // but you can assign pointer to int to a pointer to int;
    printf("this is an address of intA %p, stored in pointer a\n", a);
    printf("this is an address of intAA %p, stored in pointer aa\n", aa);
    c = aa;  //it was pointer to void, and now it is apointer to an int;
    printf("this is an address of intA %p, stored in pointer c\n", c);
    a = cc;  //was *int, now *void, it is possible in c, but not in c++
    printf("this is an address of ??? %p, stored in pointer a\n", a);
    a = b;
    printf("this is an address of floatB %p, stored in pointer b\n", b);
    printf("this is an address of floatB %p, stored in pointer a\n", a);
    cc = bb;  //is cc still pointer to void???
    a = cc;   //it has to be, otherwise there would be a mistake
    printf("this is an address of floatBB %p, \n", &floatBB);
    printf("this is an address of floatBB %p, stored in pointer cc\n", cc);
    //! printf("this is the value of floatBB %d, pointed to by pointer cc\n", *cc);
    // it is!!! a pointer to void, can't dereference such a pointer 
    // but you can assign it (or its content) to a typed pointer
    printf("this is an address of floatBB %p, stored in pointer a\n", a);
    printf("this is the value of floatBB %d, pointed by pointer a\n", *a);
    printf("this is the value of floatBB %f, pointed by pointer bb\n", *bb);
    return 0;
}