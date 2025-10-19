/*
 So the changes with the inheritance that are breaking the inheritance are
 * changing the return type
 * changing the signature:
    - name
    - type of the arguments
 */
#include <print>

class Base {
public:
    void virtual function() = 0;   //body is deligated to derived classes
    void virtual function1() {
        std::print("Base function1\n");
    }
    void virtual function2() {
        std::print("Base function2\n");
    }
};

class Derived1 : public Base{
    using Base::Base; // since c++11 inherites all the constructors of the Base
                // so no constructors neede
public:
    void virtual function() override {
        std::print("Derived1 function body");
    }
    void virtual function1() override {
        std::print("Derived1 function1\n");
    }
    void virtual function2() override {
        std::print("Derived1 function2\n");
    }
};

class Derived2 : public Base{
public:
    
    void virtual function() override {
        std::print("Derived1 function body");
    }
    void virtual function1() override {
        std::print("Derived1 function1\n");
    }
    void virtual function2() override {
        std::print("Derived1 function2\n");
    }
};

int main(int argc, const char* argv []) {
    
    //Derived1 d1();  //ERROR!
    Derived1 d2;    //declaring a variable of type without initialisation
    Derived1 d3;
    d3 = d2;
    Derived2* d4p = new Derived2();
    
    return 0;
}
