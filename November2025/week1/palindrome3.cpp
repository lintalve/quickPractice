#include <cstdio>
#include <iostream>
#include <map>

std::string palindrome(const std::string& str) {
    std::string palindrome;
    return palindrome;
}


int main(int argc, const char* argv[]) {
    std::map<int, std::string> palindromes;
    std::string palindrome;
    std::string string;
    std::cout << "enter a string" << std::endl;
    std::getline(std::cin, string);
    int count {};
    for (int i=0; i<string.size(); i++) {
        char c = string.at(i);  //not used
        
        int j {};
        while (i-(j+1) >= 0 && i+(j+1) < string.size() && string.at(i+(j+1)) == string.at(i-(j+1))) {
            j++;
            if(palindrome.length() == 0) palindrome = string.at(i);
            palindrome.insert(0, 1, string.at(i - j));
            palindrome.push_back(string.at(i + j));
            count = j > count ? j : count;
            
        }
        int k {};
        while (i-k >= 0 && i+k+1 < string.size() && string.at(i-k) == string.at(i+k+1)) {
            palindrome.insert(0, 1, string.at(i - k));
            palindrome.push_back(string.at(i + k + 1));
            k++;
            count = k > count ? k : count;
        }
        std::cout << count << std::endl;
        std::cout << palindrome << std::endl;
        if(palindrome.length() > 0) palindromes.insert({count, palindrome});
        
        palindrome.clear();
    }
    auto it = std::prev(palindromes.end());  // iterator to last (largest key)
    std::cout << "Largest key: " << it->first << ", value: " << it->second << '\n';

        

    //std::cout << count << std::endl;
    //std::cout << palindrome << std::endl;
    return 0;
}


