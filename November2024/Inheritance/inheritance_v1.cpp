#include <iostream>
#include <string>

class Object {
    int someInt{};
    string someString{};
public:
    
};

class licPlate {
    const char* number;
public:
    licPlate(const char* num) : number(num) {}
    const char* number() const { return number; }
};

class Window {};

class Vehicle {
    licPlate* lp;
};

class Car : {
    
};
