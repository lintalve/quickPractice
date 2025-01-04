#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char* arrgv[]) {
    std::string someData = "ahleflauiwhfel aliweuhfah 12341234 lkjhqwer 24643 lkjh";
    int someInt = 43252345;
    float someFloat = 314.1345f;
    double someDouble = 1352456345.4563456;
    char space = ' ';
    
    std::string path = "test2.obj";
    std::fstream fstream(path, std::ios::out);
    
    if(fstream.is_open()) {
        fstream << someData << space << someInt << space << someFloat << space << someDouble << std::endl;
        fstream.close();
    } else {
        std::cout << "file is not open" << std::endl;
    }
    
    return 0;
}
