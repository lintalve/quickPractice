#include <stdio.h>



int array[] = {3, 6, 2, 5, 9, 5, 3};        //size of the array is 28 bytes,



int main(int argc, const char* argv[]) {
    
    printf("size of the array is %zu", sizeof(array)/sizeof(*array));     //size of the array is 7 
    return 0;
}
