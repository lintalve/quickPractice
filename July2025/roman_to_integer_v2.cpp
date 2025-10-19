#include <iostream>
#include <string>
#include <print>

int roman_to_integer(const std::string& roman) {
    char L;
    char R;
    int theInt {};
    for(int j=0; j<roman.length(); j++) {
        if( )     //if larger than minus, if lower, than next one
                                                //then plus
        switch (roman.at(roman.length() - 1 - j)) {
            case 'I':
                theInt+=1;
                break;
            case 'V':
                theInt+=5;
                break;
            case 'X':
                theInt+=10;
                break;
            case 'L':
                theInt+=50;
                break;
            case 'C':
                theInt+=100;
                break;
            case 'D':
                theInt+=500;
                break;
            case 'M':
                theInt+=1000;
                break;
            default:
                break;
        }
    }
    return theInt;
}
    

int main(int argc, const char* argv[]) {
    std::string roman;
    std::cout << "enter the roman literal" << std::endl;
    std::cin >> roman;
    int integer = roman_to_integer(roman);
    
    std::print("the integer is {}", integer);
    
    return 0;
}
