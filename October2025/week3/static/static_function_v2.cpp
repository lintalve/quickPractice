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
    static const char* string_data = nullptr;
    
    if(str != nullptr) string_data = str;
    
    
    if(string_data == nullptr || *string_data == '\0') {
        return 102;
    }
    
    return *string_data++;
}

const char* s = "abcde"; //fghijklmnopqrstuvwxyz";

int main() {
    printf("%c\n", function(s));
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function());
    printf("%c\n", function(s));
    
    
    return 0;
}


