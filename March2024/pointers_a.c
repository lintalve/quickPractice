#include<stdio.h>


short int bitch = 7;

short int *ptr; // = &bitch;

//-----------------------------------------------
int main(void) {
    ptr = &bitch;
    printf("int bitch => %d\n", bitch);
    printf("pointer => %d\n", *ptr);
    return 0;
}
