//so in this file we implement the find
// and the union routine
//but we need also to make sure somehow
//that the group spreads and doesn't change its ID

#include <print>
#include <string>
#include <iostream>
#include <unordered_map>



int main(int argc, const char* argv[]) {
    
    std::unordered_map<std::string, std::string> map;
    std::string keys[] = {"do", "re", "mi", "fa", "sol", "la", "si"};
    std::string values[] = {"monday", "tuesday", "wedensday", "thursday", "friday", "satturday", "sunday"};
    
    //In C++ (and C), the comma operator evaluates all the expressions but only the last one is used.

    for(int i=0 ; i<7; i++) {
        map.emplace(keys[i], values[i]);
    }
    for (const auto& [key, value] : map) {
        std::print(" {} : {} |", key, value);
    }
    
    std::string key1;
    std::string key2;
    std::print("\nenter a pair of keys to group the values(do, re, mi, fa, sol, la, si)\n");
    while(std::cin >> key1 >> key2) {     //taking the element from the array or 
        std::string temp = map[key1];   //you need to take an element, not a key or an index, from the array
        if(temp == map[key2]) continue;   //united already
        for(auto it = map.begin(); it != map.end(); ++it) {
            if(it->second == temp) {          //element by element, matching with the copy, first iteration
                it->second = map[key2];         //second iteration, if you want to touch the element from a group
                std::print("{} : {}\n", it->second, map[key2]);
            }
        }
        std::print("\n");
        for (const auto& [key, value] : map) {
            std::print(" {} : {} |", key, value);
        }
        std::print("\n");
    }
    
    return 0;
}

