

#include <print>

class Base {
    std::string data;
public:
    Base() {
        
    }
    int function1(float fl) {
        return static_cast<int>(fl);
    }
    void function2() {
        std::print("Base::function2\n");
    }
};

class Derived1 : public Base {
public:
    int function1(int i1) {
        std::print("change of function signature\n");
        return i1;
    }
};


class Derived2 : public Base {  //so inheritance, derived classes inherit all the methods
                                //from the Base class..
                                //methods can be overloaded
                                //but there's much more, there's runtime resollution mechanism for pointers
                                //to the derived class as the base class type, polymorphism.
};


class Derived3 : public Base {
    
};

int main(int argc, const char* argv[]) {
    Derived2 d2;
    // std::print("{}\n", d2.function2());
    d2.function2();
    return 0;
}
