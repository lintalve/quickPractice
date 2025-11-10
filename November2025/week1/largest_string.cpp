#include <iostream>
#include <string>
#include <map>
/*
In this file we try to extruct the largest string from 
the vector of string
*/

std::string array[5] {
     "motherfucker",
     "fucker", 
     "string",
     "oops",
     "shitness"
};

int main(int argc, const char* argv[]) {
    //std::vector<std::string> strings;
    std::map<int, std::string> strings;
    for(const auto& str : array) {
        strings.insert({str.size(), str});
    }
    auto it = std::prev(strings.end());  // iterator to last (largest key)
    std::cout << "Largest key: " << it->first << ", value: " << it->second << '\n';


    return 0;
}