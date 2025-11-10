#include <iostream>
#include <random>

#define BAND(x)   (((x) > 5 && (x) < 10)? (x) : 0)

int main(int argc, const char* argv[]) {

    for(int i = 4; i < 10; i++) {
        int a = i;
        std::cout << "a = " << a << std::endl;
        std::cout << "\t" << "BAND(a++) = " << BAND(a++) << std::endl; 
    }

   
    return 0;
    
}