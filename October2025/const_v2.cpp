#include <print>
#include <cstdlib>

const int someInt1 = 1234; //initialisation is mandatory
extern const int extInt;  //storage is allocated, can't change the value

const double someInt2 = static_cast<double>(std::rand())/static_cast<double>(RAND_MAX); //initialisation, definition

const int* someInt1ptr = &someInt1;




namespace myNameSpace {
class Constants {
public:
    /*
    | Type / Init                                                               | Section in ELF
    |                                                                           |
    |                                                                           |
    | `static const int` initialized inside class (integral)                    | Usually **no storage**; replaced by literal                                                                                 | constants in code (if address not taken).
    | `static const int` whose address is taken, or non-integral `static const` | `.rodata` (read-only data)
    |
    | `static int` (non-const)                                                  | `.data` (initialized) or `.bss` (zero-initialized)                                    |
    */
    static const int int1 = 10;  //compil time constant. No storage allocated
    static const int int2 = 20;  //compile time constatnts
    static const int int3 = 30;
    static const int int4 = 40;
    
    
    Constants() {}
    ~Constants() {}
};

}

int main(int argc, const char* argv[]) {
    
    const int anInt1 = myNameSpace::Constants::int1; //should be a storage, can't see a number, can't be a constexpr definately
    const int anInt2 = myNameSpace::Constants::int2; //No, storage is not allocated for these const int variables inside main().
    const int anInt3 = myNameSpace::Constants::int3;
    
    std::print("{} {} {}\n", anInt1, anInt2, anInt3);
    
    const double* const ptr = &someInt2;
    std::print("{}\n",  *ptr);
    
    ptr =
    
    return 0;
}

