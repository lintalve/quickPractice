/*
This is a legitemate c code, generates no warnings with clang
in this file I tried to make sence of lowest level implementation
of strings in c and c++ and its properties
*/
#include <stdio.h>


int main(){

    char* string0 = "this is a string";           //in c it's fine

    printf("%s\n", string0);
    const char* string1 = "this is another string";
    printf("%s\n", string1);

    char charArray[] = "some undeniable shit";     //is it a conversion from literals into a char array
                                                   //or is it a legit way of initializing a char array?
                                                   //we let compiler to count the length of the array
                                                   //from number of chars in the literal

    //! char someCharArray = string0;              //error: array initializer must be an initializer list or string literal
                                                   //you can't assing pointer to array,
                                                   //even though they are somewhat the same 
                                                   //and you can do the other way around                                           

    for(int i=0; i<sizeof(charArray)/sizeof(*charArray); i++){      //with array you can use sizeof(array)
        printf("%c", charArray[i]);                                 //to get the size of the array
    }
    printf("\n");
    char* chrPtr = charArray;

    int i=0;                                
    while(chrPtr[i] != '\0') {              //very nice!
        printf("%c\n", chrPtr[i]);
        i++;                                //mutates relatively global i;
        //chrPtr++;
    }

    while(*chrPtr != '\0'){                 //no [] operator used
        printf("%c", *chrPtr);              //using the c string property, the \0 termination character
        chrPtr++;                           //to get around using char array.
    }
    printf("\n");
 
    return 0;
}