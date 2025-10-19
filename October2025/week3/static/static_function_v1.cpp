#include <cstdio>
#include <iostream>
#include <exception>
#include <string>
/*
const char* is a pointer to a rodata
*/
class myException : std::exception {
    std::string message;
public:                             //copy constructor
    myException(const std::string& msg) : message(msg) {}
    const char* what() {
        return message.c_str();
    }
};

char function(const char* str = nullptr) {   //default argument
    static const char* string_data = nullptr;   //defines only once, then a run-time assignment happens
    if(str != nullptr) {
        string_data = str;
        return string_data ? *string_data++ : 0;
    }
    char c;
    while((c = *string_data) != '\0') {
        return string_data ? c : 0;
        string_data++;
    }
}

const char* s = "abcdefghijklmnopqrstuvwxyz";

int main() {
    printf("%c\n", function(s));
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function(s));
    printf("%c\n", function());
    printf("%c\n", function());
    
    return 0;
}

