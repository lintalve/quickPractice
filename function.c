#include <stdio.h>

short int square(char x){
    x*=x;
    return x;
}

//short int squares()

int main(void) {
    int zhu = square(3);
    printf("square is %03d", zhu);
    //printf(square);
    return 0;
}
