#include <cstdlib>
#include <random>
#include <print>
#include <iostream>  //<iostream> is not included into <print>
#include "extern_const.hpp"

//const int someConstInt = 543;
//extern const int myConstInt = 543;

//const int intFunction(int integer) { return integer++; }  //ERROR: uplicating symbol, second definition

extern const int aConstInt;







int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(-15, 15);
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", dist(gen));
    std::print("{}\n", someConstInt);
//    std::print("{}\n", aConstInt);
    
    std::print("{}\n", intFunction(54));
    
    const int constInt1 = 234; //initialising in place, no storage, although the stack storage is rather fast
    const int constInt2 = 543;
    const int* const iptr = &constInt1;   //now the storage is created in .rodata
    std::cout << iptr << std::endl;
    
//    iptr = &constInt2;
    int myInt1 = 345;
    int myInt2 = 645;
    
    int* const iptr1 = &myInt1;
    
    std::cout << (*iptr1 = 333444) << std::endl; //lvalue assignment
                                                 //changing the non const int
     
    
    
    
    
    
    return 0;
}
