#include <iostream>



class WithStatic {
public:
    //integral types
    static const int size = 32;                //read only variable
    static const short someShort = 16134;           //not stored 
    static const long someLong = 57587460;
    //integral types arays
    static const int array[size];
    //pointers to integral types
    static const char* name1;  //must have out of class initialisation
    static const char* name2;  //must have out of class initialisation
    //floating point types
    //static const double someDouble = 245.970897;   //error: in-class initializer for static data member of type 'const double' requires 'constexpr' specifier
    static constexpr const float someFloat = 34.5234f; //a member with an in-class initializer must be const
    static constexpr const double someDouble = 245.970897; 
    
    //CONSTEXPRession
    static constexpr const int size = 32;                //read only variable
    static constexpr short someShort = 16134;           //read only variable
    static constexpr long someLong = 57587460;
    //non-const 
    // static int someInt = 4345; //a member with an in-class initializer must be const
    static int anInt; //must be initialised outside the class, variable
    static int array[size];
    static float fl;
public:
    int i {};
    WithStatic();
    WithStatic(int integer);
    static void changeAnInt(int ani);

};

//############# OUTSIDE CLASS DEFINITIONS ####################//

WithStatic::WithStatic() : i(654) {}
WithStatic::WithStatic(int integer) : i(integer) {}

int WithStatic::anInt = 8765;
int WithStatic::array[WithStatic::size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void WithStatic::changeAnInt(int ani) {
    anInt = ani;
}

const char* WithStatic::name1 = "WithStatic";


int main(int argc, const char* argv[]) {
    
    std::cout << WithStatic::size << std::endl;
    WithStatic ws1;  //default constructor called
    std::cout << ws1.i << std::endl;
    WithStatic ws2(6457);
    std::cout << ws2.i << std::endl;
    
    //changing from outside the class
    WithStatic::anInt = 545454;
    std::cout << WithStatic::anInt << std::endl;
    
    //changing from instance
    ws2.anInt = 656565;
    std::cout << ws2.anInt << std::endl;
    std::cout << ws2.name1 << std::endl;
    return 0;
}