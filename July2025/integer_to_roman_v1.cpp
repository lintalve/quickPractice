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
 */

int place_value(int integer) {
    double intgr = static_cast<float>(integer);
    int i{};
    while(intgr > 1) {
        intgr /= 10;
        //std::cout << intgr << std::endl;
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
        int_array_p->push_back(digit);
        std::reverse(int_array_p->begin(), int_array_p->end());
    }
    return int_array_p;
}

int integer_to_roman(std::vector<int>* vector) {
    int p_value = place_value(integer);
    
    return 0;
}


int main(int argc, const char* argv[]) {
    int integer = 384562 ;
    std::cout << "enter the integer" << std::endl;
    std::cin >> integer;
    std::cout << place_value(integer) << std::endl;
    std::vector<int>* vector = int_array(integer);
    return 0;
}
