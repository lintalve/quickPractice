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

//"MCMXCIV"
//index variable increments at the bottom of the while()

int roman_to_integer(const std::string& roman) {
    int L;
    int R;
    int theInt {};
    int j {};
    while(j < roman.length()-1) {
        switch (roman.at(roman.length() -1 -j)) {
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
        switch (roman.at(roman.length() -1 -j -1)) {       //item to grab
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
        if(j < roman.length()-1 -1) {   //not the last pair
            if(R > L) {
                theInt += R;
                theInt -= L;
                j++;
                j++;
            }else {
                theInt += R;
                j++;
            }
        } else if(j >= roman.length() -1 -1) {  //the pair is last
            if(R > L) {
                theInt += R;
                theInt -= L;
                return theInt;
                
            }else {
                theInt += R;
                theInt += L;
                return theInt;
            }
        }
    }
    return theInt;
}
    

int main(int argc, const char* argv[]) {
    std::string roman;
    std::cout << "enter the roman literal" << std::endl;
    std::cin >> roman;
    int integer = roman_to_integer(roman);
    return 0;
}
