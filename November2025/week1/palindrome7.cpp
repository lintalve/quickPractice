#include <cstdio>
#include <iostream>
#include <map>

std::string palindrome(const std::string& s) {
    std::map<int, std::string> palindromes;
    std::string word;
    //int length {};
    for (int i=0; i<s.size(); i++) {
        char c = s.at(i);  //not used
        int count {};
        int length {};
        int j {1};
        while (i-j >= 0 && i+j < s.size() && s.at(i+j) == s.at(i-j)) {
    
            if(word.length() == 0) {
                word.push_back(s.at(i));  //copy operator= call
                count++;
            }
            word.insert(0, 1, s.at(i - j));
            count++;
            word.push_back(s.at(i + j));
            count++;
            j++;
        }
        int k {};
        while (i-k >= 0 && i+k+1 < s.size() && s.at(i-k) == s.at(i+k+1)) {
            word.insert(0, 1, s.at(i - k));
            word.push_back(s.at(i + k + 1));
            k++;
            count = k > count ? k : count;
        }
        length = count > length ? count : length;
        count = 0;
        if(word.length() > 0) palindromes.insert({count, word});
        word.clear();
    }
    auto it = std::prev(palindromes.end());  // iterator to last (largest key)
    return it->second;
}


int main(int argc, const char* argv[]) {
    std::string string = "otenetar";
    std::cout << palindrome(string) << std::endl;
    return 0;
}


