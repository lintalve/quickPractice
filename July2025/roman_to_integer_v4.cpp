#include <iostream>
#include <string>
#include <print>


/*
 So length() vs index()
 1 2 3 4 5 6  -1 to shift it into an index
 0 1 2 3 4 5  -i
 5 4 3 2 1 0
 
 */
/* special cases in the solution
 is my lasiness to grow my attention*/


//index variable increments at the bottom of the while()

int roman_to_integer(const std::string& roman) {
    std::print("inside \n");
    int L;
    int R;
    int theInt {};
    int j {};
    std::print("theInt is {}\n", theInt);
    //int i1 = roman.length() -1;
    //int i2 = roman.length() -1;
    while(j < roman.length()) {
            std::cout << "j is " << j << std::endl;
            //std::cout << "ind " << roman.length() -1 -j << std::endl;
            //i1 -= j;
            //i2 = i1 - 1;
            std::print("index1 is {}\n", roman.length() -1 -j);
        if(roman.length() -1 -j -1 >= 0 && (roman.length() -1 -j -1) <= roman.length()) {
            std::print("index2 is {}\n", roman.length() -1 -j -1);
        }
            switch (roman.at(roman.length() -1 - j)) {
                case 'I':
                    R = 1;
                    break;
                case 'V':
                    R = 5;
                    break;
                case 'X':
                    R = 10;
                    break;
                case 'L':
                    R = 50;
                    break;
                case 'C':
                    R = 100;
                    break;
                case 'D':
                    R = 500;
                    break;
                case 'M':
                    R = 1000;
                    break;
                default:
                    break;
            }
        if(roman.length() -1 -j -1 >= 0 && (roman.length() -1 -j -1) <= roman.length()) {
            switch (roman.at(roman.length() -1 -j -1)) {
                case 'I':
                    L = 1;
                    break;
                case 'V':
                    L = 5;
                    break;
                case 'X':
                    L = 10;
                    break;
                case 'L':
                    L = 50;
                    break;
                case 'C':
                    L = 100;
                    break;
                case 'D':
                    L = 500;
                    break;
                case 'M':
                    L = 1000;
                    break;
                default:
                    break;
            }
        }
        std::print("R is {}\n", R);
        std::print("L is {}\n", L);
        if(R > L) {
            theInt += R;
            std::print("theInt is {}\n", theInt);
            theInt -= L;
            std::print("theInt is {}\n", theInt);
            j++;
            j++;
        }else {
            theInt += R;
            std::print("theInt is {}\n", theInt);
            j++;
        }
        
    }
    std::print("end\n");
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

