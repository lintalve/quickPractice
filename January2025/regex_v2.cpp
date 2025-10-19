#include <iostream>
#include <regex>
#include <string>

int main() {
    // Sample text to work with
    std::string text = "John's email is john.doe@example.com, and his website is https://johnsblog.com. Call him at +1-123-456-7890.";

    // Example 1: Match a pattern (e.g., email address)
    std::regex email_pattern(R"((\w+\.\w+)@(\w+\.\w+))");
    std::smatch email_match;

    if (std::regex_search(text, email_match, email_pattern)) {
        std::cout << "Found email: " << email_match[0] << std::endl;
    }

    // Example 2: Match all URLs in the text
    std::regex url_pattern(R"((https?://[\w\.\-]+))");
    std::sregex_iterator url_begin(text.begin(), text.end(), url_pattern);
    std::sregex_iterator url_end;

    std::cout << "Found URLs: " << std::endl;
    for (auto it = url_begin; it != url_end; ++it) {
        std::cout << " - " << it->str() << std::endl;
    }

    // Example 3: Replace phone numbers with [REDACTED]
    std::regex phone_pattern(R"(\+?\d{1,2}-\d{3}-\d{3}-\d{4})");
    std::string redacted_text = std::regex_replace(text, phone_pattern, "[REDACTED]");
    std::cout << "Redacted text: " << redacted_text << std::endl;

    // Example 4: Split text by spaces (tokenization)
    std::regex space_pattern(R"(\s+)");
    std::sregex_token_iterator token_begin(text.begin(), text.end(), space_pattern, -1);
    std::sregex_token_iterator token_end;

    std::cout << "Tokens: " << std::endl;
    for (auto it = token_begin; it != token_end; ++it) {
        std::cout << " - " << it->str() << std::endl;
    }

    // Example 5: Validate a string (e.g., date format: YYYY-MM-DD)
    std::string date = "2025-01-12";
    std::regex date_pattern(R"(\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");

    if (std::regex_match(date, date_pattern)) {
        std::cout << date << " is a valid date." << std::endl;
    } else {
        std::cout << date << " is not a valid date." << std::endl;
    }

    return 0;
}

