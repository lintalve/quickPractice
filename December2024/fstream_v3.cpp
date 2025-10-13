#include <iostream>
#include <fstream>

int main() {
    const char* path = "test2.obj";
    std::string someString = "fuck you bitch";
    const char* anotherString = "fuck you twice";
    std::fstream fstream(path, std::ios::out);
    
    if(!fstream.is_open()) {
        std::cout << "file is not open" << std::endl;
    }
    
    fstream << someString << ' ' << anotherString << std::endl;
    
    fstream.close();
    
    
}
