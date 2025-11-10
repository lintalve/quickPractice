#include "math.hpp"
#include <iostream>

/*
in this file we make sure that the global space, that linker will find a definition
*/

//double add(double a, double b); //compiles fine without linking phase

int main(int argc, const char* argv[]) {
    
    std::cout << add(213.34, 45.56) << std::endl; //compiler ERROR: identifier "add" is undefinedC/C++(20)
    return 0;
}