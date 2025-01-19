#include "const.h"
//#include "const copy.h"
#include <stdio.h>

int global = 1241;

int*&  givePointerByRef(int a){
    int* hj = &a;
    return hj;
    }

int*  givePointer(int a){
    int* hj = &a;
    return hj;
    }

int& getRef(int a){
    return a;
}

int main(void){
    int v = 342;
    //printf("grabing constant from another file %d\n", someExternConstInt);   //512
    //error: use of undeclared identifier 'someConstInt'
    printf("grabing constant from another file %d\n ", someConstInt);    //234
    int intish = 123;
    int* intishche = &intish;
    const int* pointerInt = &intish;    // pointer to a const int works
    const int* const constPtr_intishe = &intish;  //const pointer to a const int, I don't know 
                                             //why
    int const* const ptr_intishe = &intish;  //again, works, looks better

    int g = 354;
    float fl = 2235.2345;

    getRef(v) = intish++;
    //givePointer(v) = &g;
    * givePointer(v) = g;  //well well well well
    givePointerByRef(v) = &v;  //aaaaha, you can get a lvalue pointer by reference
    printf("some giberish %p\n", givePointer(v));
    printf("some giberish %d\n", *givePointer(v));


    const int& ref = g;   //const ref or ref to a const???
    //int& ref = g;
    //ref = v;              //!!!const reference above
    printf("some giberish %d\n", ref);

    int* ptrs[] = {&intish, &g, &v};

    ptrs[2] = &intish;
    //ptrs[2] = &intish;



    return 0;
}