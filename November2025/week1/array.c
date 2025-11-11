#include <stdio.h>
#include <stdlib.h>



#define SIZE 6   //preprocesesor substitution



double array[SIZE] = {
    [0] = 345.3,
    [1] = 23.6,
    [4] = 4.345,   //the item [2] is automatically zeroed (c23 bitches)
    [3] = 43.646,  //trailing comma is allowed or needed
};

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
    
       //usage of preincrentation and posincrementation, postfix ++ and prefix ++
    for(int i=0; i<SIZE; ++i) printf("the i is %d ", i);
    puts("\n");
    for(int i=0; i<SIZE; i++) printf("the i is %d ", i);
    puts("\n");
    //those lines above are identical
    
    
    
    return EXIT_SUCCESS;
}
