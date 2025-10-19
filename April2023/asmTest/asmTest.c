#include <stdio.h>
#define WIDTH 9

int someInt;
float x, y, z;

int multiply(int a, int b){
    return a*b;
}

const float PI = 3.14;

const char size = 23;

int array[WIDTH];
int someArray[size];


int main(void){
    for(int i=0; i<WIDTH; i++){
        array[i] = PI * i;
    }
}