#include <print>
#include <random> //you iclude random and just use the std::rand(),
                  //it might include <cstdlib> indirectly
const int someInt1 = 1234; //initialisation is mandatory
extern const int extInt;  //storage is allocated, can't change the value

const int someInt2 = std::rand(); //initialisation, definition

const int* someInt1ptr = &someInt1;




namespace myNameSpace {
class Constants {
public:
    static const int int1 = 10;
    static const int int2 = 20;
    static const int int3 = 30;
    static const int int4 = 40;
    
    
    Constants() {}
    ~Constants() {}
};

}

int main(int argc, const char* argv[]) {
    
    const int anInt1 = myNameSpace::Constants::int1;
    const int anInt2 = myNameSpace::Constants::int2;
    const int anInt3 = myNameSpace::Constants::int3;
    
    std::print("{} {} {}\n", anInt1, anInt2, anInt3);
    
    const int* const ptr = &someInt2;
    std::print("{}\n",  *ptr);
    
    return 0;
}
