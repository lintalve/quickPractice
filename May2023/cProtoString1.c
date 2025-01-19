#include <stdio.h>


int main(){

    char* string0 = "implementation";
    //! char charArray[15] = string0;      //error!
    char charArray[] = "some undeniable shit";      //interesting conversion or initiation
    const char* constantString = string0;
    for(int i=0; i<30; i++){
        printf("%c", constantString[i]);
    }
    printf("\n-------------\n");
    printf("%s\n", constantString);
    for(int i=0; i<sizeof(charArray)/sizeof(*charArray); i++){
        printf("%c", charArray[i]);
    }
    return 0;
}