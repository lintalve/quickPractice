#include <iostream>
#include <print>
#include <algorithm>

/*
 this is a solution for integer to roman conversion
 
 so we first take an integer and may be use switch to map
 integer to a roman literal
 we iterate through the list of integers and use modulo to
 destinguish whether we are dealing with over the fife
 we see the pattern that if the integer is < than 4, than
 we add current roman literal i%4 + 1 times in a row, than
 switch to the nex
 The rule with M, with 1000. The rule for it is that M is
 used to represent digit only up to 3000.
 */

int place_value(int integer) {
    double intgr = static_cast<float>(integer);
    int i{};
    while(intgr > 1) {
        intgr /= 10;
        i++;
    }
    return i;
}

std::vector<int>* int_array(int integer) {
    int p_value = place_value(integer);
    int d = 1;
    std::vector<int>* int_array_p = new std::vector<int>;
    for(int i=0; i<p_value; i++) {
        int d = d * 10;
        int digit = integer%d;
        //int_array_p->insert(digit);
    }
    std::reverse(int_array_p->begin(), int_array_p->end());
    int i {};
    return int_array_p;
}

std::string integer_to_roman(int integer) {
    int p_value = place_value(integer);
    std::vector<int> array;
    char rom[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    std::string roman;
    for(int i=0; i<p_value; i++) {
        int d = integer%10;
        integer /= 10;
        //std::print("digit {}\n", d);
        array.push_back(d);
    }
    //std::reverse(array.begin(), array.end());     //the way to reverse a vector<>
    std::print("number in the array \n");
    for(int i=0; i<array.size(); i++) {
        std::print("{}", array[array.size() -1 -i]);
    }
    std::print("\n");
    int j {};
    for(int digit : array) {
        std::print("current digit {}\n", digit);
        if(digit%5 < 4 && digit/5 < 1) {
            for(int k=0; k<digit%5; k++) {
                roman.insert(0, 1, rom[2*j]);
            }
        }else if(digit%5 < 4 && digit/5 > 0) {
            for(int k=0; k<digit%5; k++) {
                roman.insert(0, 1, rom[2*j]);
            }
            roman.insert(0, 1, rom[2*j + digit/5]);
        }
        else if(digit%5 == 4 && digit/5 > 0) {
            roman.insert(0, 1, rom[2*j + 1 + digit/5]);
            roman.insert(0, 1, rom[2*j]);
        }else if(digit%5 == 4 && digit/5 < 1) {
            roman.insert(0, 1, rom[2*j + 1]);
            roman.insert(0, 1, rom[2*j]);
        }else if(digit%5 == 0 && digit/5 > 0) {
            roman.insert(0, 1, rom[2*j + 1]);
        }else if(digit%5 == 0 && digit/5 < 1) {
            std::print("digit is 0");
        }else if(j >= 3) {
            for(int k=0; k<digit; k++) {
                roman.insert(0, 1, rom[2*j]);
                std::print("adding M\n");
            }
         
         
        }
        j++;
    }
    return roman;
}


int main(int argc, const char* argv[]) {
    int integer = 4562 ;
    std::cout << "enter the integer" << std::endl;
    std::cin >> integer;
    std::cout << "place value"<< place_value(integer) << std::endl;
    //std::vector<int>* vector = int_array(integer);
    std::string roman = integer_to_roman(integer);
    std::print("{}\n", roman);
    return 0;
}

