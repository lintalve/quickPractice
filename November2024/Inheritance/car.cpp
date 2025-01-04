#include <iostream>
#include <string>
#include <OpenGL/gl.h>  // for OpenGL functions
#include <OpenGL/glu.h> // for OpenGL utility functions

class Object {
    int someInt{};
    string someString{};
public:
    
};

class LicPlate {
    //so these (const char* string literals) are
    //stored in read-only area of the memory
    //deleting them is undefined behaviour
    const char* number {nullptr};
public:
    licPlate(const char* num) : number(num) {}
    const char* number() const { return number; }
};

class Window {
    bool closed{};
public:
    Window() : closed(true) {}
    bool closed() const {return closed;}
    //no need for custom copy constructor, bitwise copying is fine
    //no need for custom copy assignment operator, bitwise copying is fine
    //no need move?? pedantic approach says yes
    Window(Window&& w) noexcept {
        closed = w.closed;
        W.closed = true; //zum beischpiel
    }
    Window& operator=(Window&& w) noexcept {
        closed = w.closed;
        W.closed = true; //zum beischpiel
        return *this;
    }
    //no need for custom destructor, no resources
};

class Door {
    Window* win {nullptr};
    //class has pointer, so it needs custom 6 functions
    bool closed{};
    //shouldn't be public, it'll leave the object empty
    Door() {}  //for a dynamic array
public:
    Door(Window* w) : win(w) closed(true) {
        std::cout << "Door Constructor" << std::endl;
    }
    //Need custom copy constructor to avoid the stuation
    //where the copied pointer points to the same window
    
    //Yes, the constructor initializer list does have access
    //to private members of the passed const Door& d object,
    //provided that d is of the same class type as the one being constructed.
    Door(const Door& d) : win(new Window(d.win)) closed(d.closed) {
        std::cout << "Door Copy-constructor" << std::endl;
    }
    //Copy assignment operator
    Door& operator=(const Door& d) {
        win = new Window(d.win);
        closed = d.closed;
        return *this;
    }
    //Move constructor
    Door(Door&& d) noexcept : win(d.win), closed(d.closed) {
        //same rule, as long is object is the same Type
        //as the constructing object, private parts are accessable
        //leave moveed from obj in empty valid state
        d.win = nullptr;
        closed = false;
    }
    Door& operator=(Door&& d) noexcept {
        win = d.win;
        closed = d.closed;
        //leave...
        d.win = nullptr;
        d.closed = false;
    }
    ~Door() {
        delete win;
    }
};

class Vehicle {
    //If MyClass does not have a default constructor, and the braces are empty (i.e., {}),
    //value-initialization occurs, which means that obj is initialized to its default value
    //(for example, zero for primitive types or calling the default constructor for class members).
    LicPlate lp {};  //CALLS the defaault constructor right there!!
    
    float top_speed {};
public:
    Vehicle() {
        lp.number = "DE38276";
        top_speed = 230;
    }
};

class Car : public Vehicle {
    //Using a pointer to the base class allows you to work
    //with the derived class objects through the base class interface,
    //which is a core principle of polymorphism.
    Body* body {nullptr};
    Door* rightFront_d {nullptr};
    Door* leftFront_d {nullptr};
    Door* rightRear_d {nullptr};
    Door* rightRear_d {nullptr};
    Door* rear_d {nullptr};
    
    Wheel* rightFront_w {nullptr};
    Wheel* leftFront_w {nullptr};
    Wheel* rightRear_w {nullptr};
    Wheel* leftRear_w {nullptr};
public:
    Car() { std::cout << "Default constructor" << std::endl; }
    Car(Body* bod,   Door* rFront_d, Door* lFront_d, Door* rRear_d, Door* rRear_d, Door* re_d
                      Wheel* rFront_w, Wheel* lFront_w, Wheel* rRear_w, Wheel* lRear_w)
            : Vehicle(), body(bod), rightFront_d(rFront_d), leftFront_d(lFront_d), rightRear_d(rRear_d)
};

