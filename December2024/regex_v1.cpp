/*
 The provided code will not work as intended because std::regex_match checks if the entire input string matches the given regex pattern. In your case, the pattern R"(v)" only matches the character v, while the entire input string is "v 0.1 0.2 0.3". Since the entire string doesn't match, std::regex_match will fail, and matches will remain empty.
 */
#include <iostream>
#include <regex>



int main(int argc, const char* argv[]) {
    std::string string = "v 0.1 0.2 0.3";
    std::regex pattern(R"(v)");
    std::smatch matches;
    std::regex_match(string, matches, pattern);
    std::cout << matches[0];
}
