/*
This is a legitemate c code, generates no warnings with clang
in this file I tried to make sence of lowest level implementation
of strings in c and c++ and its properties
*/
#include <stdio.h>


int main(){

    char* string0= "this is a string";   //generates warning in C++! Depricated, you should use const char*
                                         //this is allowed in c though
    printf("%s\n", string0);
    const char* string1 = "this is another string";
    printf("%s\n", string1);

    char charArray[] = "some undeniable shit";     //is it a conversion from literals into a char array
                                                   //or is it a legit way of initializing a char array?
                                                   //we let compiler to count the length of the array
                                                   //from number of chars in the literal
    for(int i=0; i<sizeof(charArray)/sizeof(*charArray); i++){
        printf("%c", charArray[i]);
    }
    printf("\n");

    char* chrPtr = charArray;                     
    
    int i=0;
    while(chrPtr[i] != '\0') {
        printf("%c\n", chrPtr[i]);
        i++;
        //chrPtr++;
    }


    return 0;
}