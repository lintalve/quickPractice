#include <stdio.h>

class SomeClass{
public:
    float x;
    float y;
    SomeClass(float x, float y) : x(x), y(y) {};  //list initialization

    SomeClass methd(float x, float y)  { return SomeClass(x, y); }
    static SomeClass mfunc(float x, float y)  { return SomeClass(x, y); }
    
    
};

SomeClass func(float x, float y){
    SomeClass sm = SomeClass(x, y);
    return sm;
}

int main(void){
    
    //! SomeClass sm = SomeClass.func(23.234f, 2.456f); //won't work, method isn't static
    SomeClass sm = SomeClass(123.23f, 2.564f);  //calling constructor
    SomeClass some = sm.methd(23.234f, 2.456f);  //method!!
    SomeClass someCl = func(23.234f, 2.456f);    // calling global function!!
        //which could be included from other file;
    SomeClass sc = SomeClass::mfunc(4.5f, 5.6f);  //Static member functions have no *this pointer
        //and you need to use scope resolution operator '::'
    int shit = int(5);  //default ocnstructor of inbuilt type
    return 0;
}