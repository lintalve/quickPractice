#include <iostream>
#include <string>
#include <map>
/*
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 10**4
s consists of English letters, digits, symbols and spaces.
*/

std::string longest_u(const std::string& input) {
    std::map<int, std::string> words;
    std::string unique_buffer;
    std::string word;
    char c;
    int i {};
    while( i<input.length()) {
        int count = 0;
        while(i<input.length() && unique_buffer.find(c = input.at(i)) == std::string::npos) {
            unique_buffer.push_back(c);
            word.push_back(c);
            count++;
            i++;
        }
        words.insert({count, word});
        unique_buffer.clear();
        word.clear();
        //i++;
    }

    auto it = std::prev(words.end()); 
    return it->second;
}


int main(int argc, const char* argv[]) {
    
    std::string input = "barekads";
    std::cout << longest_u(input) << std::endl;
    return 0;
}