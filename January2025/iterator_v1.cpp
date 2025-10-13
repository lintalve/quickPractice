#include <exception>
#include <string>

class myException : public std::exception {
    std::string msg {};
public:
    myException(const std::string& message) : msg(message) {}  //for when you throw it
    const char* what() const noexcept override {
        return msg.c_str();
    }
};
