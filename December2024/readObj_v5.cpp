#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, const char* argv[]) {
    std::string path = "cube.obj";
    std::ifstream file(path);
    
    
    
    
    
    std::istringstream iss(path);
    
    std::cout << string3;
    std::string string;
    std::string string2;
    if(!file.is_open()) {
        std::cout << "file is not open!!" << std::endl;
        

        //output stringstream
        std::ostringstream oss;
        oss << file.rdbuf();  //load the ifstream content into ostringstream as sring
        std::string string3 = oss.str();
        std::cout << string3;
    }
    while (std::getline(file, string)) {
        std::cout << string << std::endl;
    }
    
    
    
    
    std::getline(file, string2);
    std::cout << string2;
    
    char element;
    double x, y, z;
    char comma1, comma2;
    
    while(iss >> element >> x >> comma1 >> y >> comma2 >> z && element == 'v' && comma1 == ',' && comma1== ',') {
        //if(element == #) {
            printf("%c", element);
        //}
    }
    file.close();
    return 0;
}
