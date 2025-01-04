//in this file we seccessfully read file content into a string
//than print the content of the string to the terminal

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, const char* argv[]) {
    std::string path = "cube.obj";
    std::ifstream file(path);
    

    if(!file.is_open()) {
        std::cout << "file is not open!!" << std::endl;
        }
    //output stringstream
    std::ostringstream oss;
    oss << file.rdbuf();  //load the ifstream content into ostringstream as sring
    std::string string3 = oss.str();
    std::cout << string3;
    file.close();
    return 0;
}
