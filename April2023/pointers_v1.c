#include <stdio.h>



int main(void){
    int array0[] = {12, 32, 43, 6, 7, 8, 4, 23, 12, 765};
    int someItem0 = *array0+1;     //dereferencing preceeding addition
    int someItem1 = *(array0+1);   //adding one to the delivered item
    printf("this is the item from ptr arythmetics %d \
            from address %p \n", someItem0, array0+3);
    printf("this is the item from ptr arythmetics %d \
            from address %p \n", someItem1, array0+4);
    int i=0;
    printf("this should be the size of our array %lu", sizeof(array0));  // very good!!
    for(; i<sizeof(array0)/sizeof(*array0); i++){   //very nice!!!
        printf("this is the address of element %d -- %p \n ", i, array0+i);
    }
    return 0;
}