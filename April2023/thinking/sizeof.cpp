#include <stdio.h>

int main(void){
    
    double array[] = {123.253, 654.23, 876.342, 452.647};
    printf("this is the size of an entire array %zu\n", sizeof(array));
    printf("this is the size of the first item in the array %zu\n", sizeof(array[0]));
    printf("this is the length of the array %lu\n", sizeof(array)/sizeof(array[0]));
    printf("this is the length of the array %lu\n", sizeof(array)/sizeof(*array));  //dereferencing
    return 0;                    // array is a pointer to the first byte of the firrst item
}