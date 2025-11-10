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
        for(int j=0; j<10; j++) {
            if(string.at(i+j) == string.at(i-j) && i-j >= 0 && i+j < string.size()) {
                count++;
                palindrome.push_back(string.at(i+j));
            }
            //if((string.at(i+j)== c || string.at(i+j+1) == string.at(i-j)) && i-j >= 0 && i+j+1 < string.size() ) {
            //    palindrome.append(string.at(i+j))
            //    count++;
            //
            //}
            if(string.at(i+j+1) != c || string.at(i+j+1) != string.at(i-(j+1))) {
                count = 0;
                break;
            }
        }
    }
    std::cout << count << std::endl;
    
    std::cout << palindrome << std::endl;
    return 0;
}
