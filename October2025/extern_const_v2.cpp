#include <cstdio>
#include <iostream>
#include <cmath>
#include "extern_const.hpp"

const int someConstInt = 345;  //redefinition of someConstInt
                                //you declare this const to use in your current translation unit

//const int myConstInt = 765;  //this creates a duplicate symbol with the linker.

//const int someConstInt = 2345; //this works why???


//const int intFunction(const int integer) { return integer++; }  //ERROR: modifying the const, that is copied into
//const int intFunction(int integer) { return integer++; } //returns the same, than increments
const int intFunction(int integer) { return ++integer; }  //increments than returns



constexpr int a = 354;
constexpr int b = a + 234;

constexpr int function1(const int a = 3) {
//    return pow(a, 2);
    return a*a;
}



