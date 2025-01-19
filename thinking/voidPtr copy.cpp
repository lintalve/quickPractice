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
    
    //! a = b;  //gives a warning, but not an error in in c
    printf("this is an address of floatBB %p, \n", &floatBB);
    printf("this is an address of floatBB %p, stored in pointer bb\n", bb);
    c = bb;  //is c still pointer to void???
    a = c;   //it has to be, otherwise there would be a mistake
    printf("this is an address of floatBB %p, stored in pointer c\n", c);
    printf("this is an address of floatBB %p, stored in pointer a\n", a);
    printf("this is the value of floatBB %f, dereferenced from the pointer a\n", *a);
    // ! a is still a pointer to int, thus can't be dereferenced to a float
    b = a;
    printf("this is an address of floatBB %p, stored in pointer b\n", b);
    printf("this is the value of floatBB %f, dereferenced from the pointer b\n", *b);

        return 0;
}