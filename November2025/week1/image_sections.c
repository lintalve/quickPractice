#include <stdio.h>

/*
image dump sections /Users/test/Documents/programming/cpp/quickPractice/November2025/week1/image 
*/

int unint;    //should go to __DATA __bss, went to exec.__DATA.__common
short unshort;  //should go to __bss, went to __DATA.__common + 4
float unfloat;  //should go to __bss, went to __DATA.__common + 4


int someInt = 234;   //should be __data, went to __DATA.__data + 0

const int constInt = 23454;   //should go to __TEXT.__const

//limits linkage, use for this file, some parameter for only this file
static int someStaticInt = 645;   //not found
static const int someStaticConstInt = 654;    //not foound

const char* str = "motherfucker";    //should go to __TEXT.__cstring, went to __DATA.__data + 8

int main(int argc, const char* argv[argc+1]) {        //stack
    int anInt = 2345;

    float aFloat = 0.2345;

    const char* string = "some motherfucker";
return 0;
}