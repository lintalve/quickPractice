#include <cstdio>
#include <iostream>
#include <map>

std::string palindrome(const std::string& s) {
    std::map<int, std::string> palindromes;
    std::string palindrome;
    int count {};
    for (int i=0; i<s.size(); i++) {
        char c = s.at(i);  //not used
        int j {};
        while (i-(j+1) >= 0 && i+(j+1) < s.size() && s.at(i+(j+1)) == s.at(i-(j+1))) {
            j++;
            if(palindrome.length() == 0) {
                palindrome = s.at(i);
                count++;
            }

            palindrome.insert(0, 1, s.at(i - j));
            count++;
            palindrome.push_back(s.at(i + j));
            count++;
            count = j > count ? j : count;
            
        }
        int k {};
        while (i-k >= 0 && i+k+1 < s.size() && s.at(i-k) == s.at(i+k+1)) {
            palindrome.insert(0, 1, s.at(i - k));
            palindrome.push_back(s.at(i + k + 1));
            k++;
            count = k > count ? k : count;
        }
        if(palindrome.length() > 0) palindromes.insert({count, palindrome});
        
        palindrome.clear();
    }
    auto it = std::prev(palindromes.end());  // iterator to last (largest key)
    return it->second;
}


int main(int argc, const char* argv[]) {
    std::string string = "telenelet";
    std::cout << palindrome(string) << std::endl;
    return 0;
}


