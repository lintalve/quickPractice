#include <iostream>
#include <print>
#include <format>

/*
 In C++ and many other languages, static member functions of a class are functions that:
 * Belong to the class itself, not to a specific object.
 * Can be called without creating an instance of the class.
 * Cannot access non-static data members or non-static member functions (since those require an instance).
 Are usually used for “utility” methods tied conceptually to the class.
 */

class myException : std::exception {
    std::string message;
public:
    myException(const std::string& msg) : message(msg) {
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Static {
    static int staticInt;
private:
    int theInt {};
    std::string str1;
    Static(int someInt) : theInt(someInt), str1("som") {
        std::print("setup theInt: {} str1: {} and entered the private constructor\n", someInt, str1);
    }
public:
    static Static* fabric(int passingInt);
    std::string data() {
        if(str1.length() < 4) throw myException("the data is too short");
        return str1;   //this would be copy illimination
    }
};

int Static::staticInt = 12412;

Static* Static::fabric(int passingInt) {
    std::print("entered the fabrication static function\n");
    return new Static(passingInt);
}

int main(int argc, const char* argv[]) {
    
    Static* st1 = Static::fabric(934876);
    try{
        std::print("{}\n", st1->data());
    } catch(const myException& e) {
        std::print("{}\n", e.what());
    }
    delete st1;
    return 0;
}
