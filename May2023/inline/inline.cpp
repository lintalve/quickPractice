/*
In this file we study the functionality of inline functions of cpp
*/

#include <cmath>
#include <cstdio>


inline static const int getSum(int a, int b){   //here we go, inline function
    return abs(a + b);
}

int main(void){

    unsigned int x = getSum(6, 8);
    
    return 0;
}