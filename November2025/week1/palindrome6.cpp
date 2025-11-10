#include <iostream>
#include <string>

std::string palindrome(const std::string& s) {
    std::string longest;

    for (int i = 0; i < s.size(); ++i) {
        // Odd-length palindromes
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > longest.size())
                longest = s.substr(l, r - l + 1);
            --l;
            ++r;
        }

        // Even-length palindromes
        l = i; r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > longest.size())
                longest = s.substr(l, r - l + 1);
            --l;
            ++r;
        }
    }
    return longest;
}

int main() {
    std::string str = "telenelet";
    std::cout << palindrome(str) << std::endl;
    return 0;
}
