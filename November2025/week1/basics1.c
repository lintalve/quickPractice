#include <stdio.h>

/*
image dump sections /Users/test/Documents/programming/cpp/quickPractice/November2025/week1/image 
In this file we explore compiler explorer assembly
*/

int unint;    //should go to __DATA __bss, went to exec.__DATA.__common
short unshort;  //should go to __bss, went to __DATA.__common + 4
float unfloat;  //should go to __bss, went to __DATA.__common + 4


int someInt = 234;   //should be __data, went to __DATA.__data + 0
//const still have to be initialised in place of declaration
const int constInt = 23454;   //should go to __TEXT.__const, went to __TEXT.__const + 4

//limits linkage, use for this file, some parameter for only this file
static int someStaticInt = 645;   //should be __data, went to __DATA.__data + 0
static const int someStaticConstInt = 654;    //should go to __TEXT.__const, went to __TEXT.__const + 4

const char* str = "motherfucker";    //should go to __TEXT.__cstring, went to __DATA.__data + 8

int main(int argc, const char* argv[argc+1]) {        //stack
    int anInt = 2345;

    float aFloat = 0.2345;

    const char* string = "some motherfucker";  //pointer points to __TEXT.__cstring
    string = "a";  //now it points to __TEXT.__cstring, pointer lives on the stack
return 0;
}