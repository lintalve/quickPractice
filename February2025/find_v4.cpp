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
    while(std::cin >> key1 >> key2) {
        std::string temp = key1;
        if(map[temp] == map[key2]) continue;
        for(auto it = map.begin(); it != map.end(); ++it) {
            if(it->first == temp) {
                map[temp] = map[key2];
                std::print("{} : {}\n", map[temp], map[key2]);
            }
        }
        std::print("\n");
        for (const auto& [key, value] : map) {
            std::print(" {} : {} |", key, value);
        }
    }
    
    return 0;
}
