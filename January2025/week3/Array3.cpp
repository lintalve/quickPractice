//: C16:Array3.cpp
// Built-in types as template arguments
//Without iterators
#include "require.h"
#include <iostream>
using namespace std;
template<typename T, int size = 100>    //so these arguments are places by compiler in assemply as immediates
class Array {
    T array[size];
public:
    T& operator[](int index) {
        require(index >= 0 && index < size,
                "Index out of range");
        return array[index];
    }
    int length() const { return size; }
};

class Number {
    float f;
public:
    Number(float ff = 0.0f) : f(ff) {}
    Number& operator=(const Number& n) {   //is it needed to implement? wouldn't shalow copy suffice? should
        f = n.f;
        return *this;
    }
    operator float() const { return f; }
    
    friend ostream& operator<<(ostream& os, const Number& x) {
        return os << x.f;
    }
};
//Here T argument goes straight to the Array<T, size>   ;size goes straight into assembly as an emmidiate
template<typename T, int size = 20>      //acts similar to sttic member variable
class Holder {
    Array<T, size>* np;      //this is the reason for the class
                             //pointer and as a private the other Template class
                             //just as it were to be pointer to MyClass array[]
public:
    Holder() : np(nullptr) {}
    T& operator[](int i) {
        require(0 <= i && i < size);
        if(!np) np = new Array<T, size>;    //lasy implementation
                                            //meaning you initialise the pointer NOT until you start using
                                            //NOT just when you declare the varr of the class
                                            //just so you could declare a lot of such objects, without allocation
        return np->operator[](i);    //inderection
    }
    int length() const { return size; }
    ~Holder() { delete np; }       //delete can delete only what was new'ed, meaning destructo would frickout if it were to delete what was not allocated with new, that's what is meant in the book.
    //suppose you are to delete HisClass* , and it wasn't allocated in the constructor. Thus destructor must "know" the type
};

int main() {
    Holder<Number> h;   //Number is passed further inside
    for(int i = 0; i < 20; i++) h[i] = i;
    for(int j = 0; j < 20; j++) cout << h[j] << endl;
} ///:~
