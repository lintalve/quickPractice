#include <stdio.h>
#include <stdlib.h>

const int SIZE = 6; //const global variable , have storage
//warning: variable length array folded to constant array as an extension


double array[SIZE] = {
    [0] = 0.3,
    [1] = 1.6,
    [4] = 4.345,   //the item [2] is automatically zeroed (c23 bitches)
    [3] = 3.646,  //trailing comma is allowed or needed
};

int main(int argc, const char* argv[argc+1]) {
    
       //usage of preincrentation and posincrementation, postfix ++ and prefix ++
    for(int i=0; i<SIZE; ++i)
        printf("the array[%i] is %g and its square is %g\n", i, array[i], array[i] * array[i]);
    
        
    
    
    return EXIT_SUCCESS;
}

