//: C16:Array3.cpp
// Built-in types as template arguments
//Without iterators
#include "require.h"
#include <iostream>
#include <exception>

class MyException : public std::exception {
    std::string msg;
public:
    //Constructor
    MyException(const std::string& message) : msg(message) {}  //message must be const, probably there's some method that is const..
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

using namespace std;
template<class T, int size = 100>    //so these arguments are places by compiler in assemply as immediates
class Array {
    T array[size];
public:
    T& operator[](int index) {
        if(index >= 0 && index < size) {
            return array[index];
        } else { throw MyException("Index out of range, bitches"); }
    }
    int length() const { return size; }
};

class Number {
    float f;
public:
    Number(float ff = 0.0f) : f(ff) {}
    Number& operator=(const Number& n) {
        f = n.f;
        return *this;
    }
    operator float() const { return f; }
    
    friend ostream& operator<<(ostream& os, const Number& x) {
        return os << x.f;
    }
};

template<class T, int size = 20>
class Holder {
    Array<T, size>* np;
public:
    Holder() : np(nullptr) {}
    T& operator[](int i) {
        require(0 <= i && i < size);
        if(!np) np = new Array<T, size>;
        return np->operator[](i);
    }
    int length() const { return size; }
    ~Holder() { delete np; }
};

int main() {
    Holder<Number> h;
    for(int i = 0; i < 101; i++) h[i] = i;
    for(int j = 0; j < 20; j++) cout << h[j] << endl;
} ///:~

