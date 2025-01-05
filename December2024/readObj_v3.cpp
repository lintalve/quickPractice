#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, const char* argv[]) {
    std::ifstream file;
    std::string path = "cube.obj";
    std::string string;
    file.open(path, std::ios::in);
    if(file.is_open()){
        std::getline(file, string);
        std::cout << string << std::endl;
    }
    std::cout << string;
    file.close();
    
    
    return 0;
}
