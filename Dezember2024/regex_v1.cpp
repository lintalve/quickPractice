#include <iostream>
#include <regex>



int main(int argc, const char* argv[]) {
    std::string string = "v 0.1 0.2 0.3";
    std::regex pattern(R"(v)");
    std::smatch matches;
    std::regex_match(string, matches, pattern);
    std::cout << matches[0];
}
