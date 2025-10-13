#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    printf("RAND_MAX define for my macbook pro is %d\n", RAND_MAX);
    printf("which is the max value of a signed int\n");
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);

    srand(time(NULL));          //this is how you seed inbuilt random generator for different sequence 
                                //every time
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);
    srand(time(NULL));     
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);
    printf("random integer from 0 to 9 in C is %d every time\n", rand() % 10);
    printf("this is the time in seconds since 1st January 1970 %ld\n", time(NULL));
    printf("this is the size of the return value of time(NULL); %lu\n", sizeof(time(NULL)));  //8 bytes long int
}