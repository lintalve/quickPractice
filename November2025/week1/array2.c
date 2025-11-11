#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

const int SIZE = 6; //const global variable , have storage
//warning: variable length array folded to constant array as an extension

//array is a pointer to the first element
double array[SIZE] = {
    [0] = 0.3,
    [1] = 1.6,
    [4] = 4.345,   //the item [2] is automatically zeroed (c23 bitches)
    [3] = 3.646,  //trailing comma is allowed or needed
};

int main(int argc, const char* argv[argc+1]) {
    
       
    int j=0;
    printf("%p\n", array);
    //pointer arithmetic is important to undestand that to ptr++ is to add size_of(int)
    //pointer difference is the difference between two pointers in elements, not bytes!!
    ptrdiff_t diff_bytes = (char*)&array[3] - (char*)array; // difference in bytes = 12

    printf("%td\n", &array[3] - array);  //pointer diference
    
    
        
    
    
    return EXIT_SUCCESS;
}


