#include <stdio.h>     //in c we have to write.h
#include <stdlib.h>

/*
 in this file we prove that one can make as many declaration
 */

int function(int i);
int function(int i);
int function(int i);    //you can declare the same symbol as many times as you want
int function(int i);


int function(int i ) {
    return ++i;
}

//int function(int i) { return i*i; } //error: redefinition of 'function'

int a;
int a;
int a;//you can declare the same symbol as many times as you want
int a;

int a = 345;

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
    
    int a = 234; // local variable eclipses global variable in a local scope
    
    
    return EXIT_SUCCESS;
}
