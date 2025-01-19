#include "const.h"
#include <stdio.h>

extern const int anotherConstInt = 234;

int main(void){
    
    int someint = someConstInt;
    printf("this is so called static unreachable const someConstInt %d\n", someConstInt);
    int array[someConstInt];
    for(int i=0; i<sizeof(array)/sizeof(*array); i++){
        array[i] = i;
    }
    int c = 6;
    printf("this is the value of the cell %d\n", array[c=3]);  //nice!!, keeps c = 3;
    printf("this is the value of the cell %d\n", array[3]);
    printf("this is the value of the cell %d\n", array[0]);
    printf("this is the value of the cell %d\n", array[1]);
    printf("this is the value of the cell %d\n", array[2]);
    printf("this is the value of the cell %d\n", c);           //c is still 3, not 6;
    return 0;
}