#include <cstdio>
#include <iostream>

std::string palindrome(const std::string& str) {
    std::string palindrome;
    return palindrome;
}


int main(int argc, const char* argv[]) {
    std::string palindrome;
    std::string string;
    std::cout << "enter a string" << std::endl;
    std::getline(std::cin, string);
    int count {};
    for (int i=0; i<string.size(); i++) {
        char c = string.at(i);
        //palindrome = string.at(i);
        int j {};
        while (i-j >= 0 && i+j+1 < string.size() && string.at(i-j) == string.at(i+j+1)) {
            palindrome.insert(0, 1, string.at(i - j));
            palindrome.push_back(string.at(i + j + 1));
            j++;
            }
        std::cout << j << std::endl;
        std::cout << palindrome << std::endl;
        }

    //std::cout << count << std::endl;
    //std::cout << palindrome << std::endl;
    return 0;
}


