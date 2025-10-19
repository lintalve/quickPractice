#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char* argv[]) {
    std::string path = "new.obj";
    std::fstream fstream(path, std::ios::out);
    if(!fstream.is_open()) {
        std::cout << "file is not open" << std::endl;
    }
    fstream << "sheise auf dich you cunt" << std::endl;
    fstream.close();
    
    
    return 0;
}
