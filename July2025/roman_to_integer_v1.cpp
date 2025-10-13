#include <iostream>
#include <print>


char charray[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', };

typedef enum class Roman {
    I,
    V,
    X,
    L,
    C,
    D,
    M
} roman;

int roman_to_int(Roman r) {
    switch(r) {
        case roman::I :
            //std::print("motherfucker {}", 1);
            return 1;
        case roman::V :
            //std::print("motherfucker {}", 1);
            return 5;
        case roman::X :
            //std::print("motherfucker {}", 1);
            return 10;
        case roman::L :
            //std::print("motherfucker {}", 1);
            return 50;
        case roman::C :
            //std::print("motherfucker {}", 1);
            return 100;
        case roman::D :
            //std::print("motherfucker {}", 1);
            return 500;
        case roman::M :
            return 1000;
        default :
            std::print("something to print");
            break;
    }
    
}

int main() {
    std::string str;
    std::cout << "enter a roman numeral" << std::endl;
    std::cin >> str;
    Roman someRoman = roman::I;
    int someInt = roman_to_int(someRoman);
    return 0;
}
