#include <iostream>
#include <regex>
#include <string>
#include <ranges>

int main() {
    std::string text = "C++20 is awesome! Let's learn regex.";
    std::regex word_pattern("\\w+"); // Match words

    // Use std::ranges::subrange for regex_search iteration
    for (auto it = std::sregex_iterator(text.begin(), text.end(), word_pattern);
         it != std::sregex_iterator(); ++it) {
        std::cout << "Matched word: " << it->str() << std::endl;
    }

    return 0;
}

