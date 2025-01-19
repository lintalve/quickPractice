#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main() {
    
    std::string path = "cube.obj";
    std::ifstream file(path);
    std::string string;
    
    if(!file.is_open()) {
        std::cout << "file not open!" << std::endl;
    }
    std::ostringstream oss;
    oss << file.rdbuf();
    string = oss.str();
    
    file.close();
    
    std::string string2;
    std::istringstream iss(string);
    
    
    
    while(std::getline(iss, string2) ) {
        //std::cout << "line " <<  string2 << std::endl;
        
        std::regex pattern(R"(v\s+)");  //[0-9.+], + means digit or '.'
        

        std::smatch matches;   //an array that contains matched characters
        
        if(std::regex_match(string2, matches, pattern)) {
            std::cout << matches[0];
            std::cout << matches[1];
            std::cout << matches[2];
            std::cout << matches[3];
        }
        //char element;
        //double x, y, z;
        //char comma1, comma2;
                
    }
        
    
        return 0;
    
}
