#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int size = 16; //size in elements

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
    
    int* array = malloc(size * sizeof(int));  //you dont cast in c, you cast in c++ because it is mandatory
    memset(array, 0, size * sizeof(int));
    int* a_ptr = array;
    for(int k=0; k<size; k++) {
        *(a_ptr + k) = 2*k+1;   //using k to generate odd natural numbers arithmetic progression
    }
    
    
    for(int i=0; i<size; i++) {
        printf("element %i is %i \n", i,  *(a_ptr + i));  //pointer arithmetic in the form arddress + int
        
    }
    
    for(int j=0; j<size; j++) {
        printf("element %i is %i \n", j, *a_ptr);
        a_ptr++;                  //incrementation of a  pointer of type int is with step 4 bytes
    }
    int new_size = size-4;
    array = realloc(array, new_size);  //moves or maintains the content, which is truncated to the new size
    a_ptr = array;
    
    for(int l=0; l<=new_size; l++) {
        printf("element %i is %i \n", l, *a_ptr);
        a_ptr++;                  //incrementation of a  pointer of type int is with step 4 bytes
    }
    
    
    free(array); //you free to avoid memory leak
    array = nullptr;
    a_ptr = nullptr;
    
    return EXIT_SUCCESS;
}
