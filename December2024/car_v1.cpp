// Include standard OpenGL headers (for things like gl.h)
      // OpenGL extensions
#include "GL3/gl3.h"        // Core OpenGL 3.0+ headers

//Include windowing and utility libraries
#include <GLFW/glfw3.h>     // GLFW for window/context management
#include <GL/freeglut.h>    // FreeGLUT, only if needed

std::fstream myfile;   //manchmal muss man bfore declarieren

class Vehicle {};
class Car {};

class MercedesC : public Car {
    static int vertexIDsArray[];
public:
    bool door {};
    bool door {};
    
    double positions[];
    double normals[];
    Car() : door() {
                                    //open to write, 'out' means to write out to file
        //fstream.open("Car.obj", std::ios::out);
        myfile.open("Car.obj", std::ios::in);
        if(myfile.isopen()) {
            myfile <<
        }
        glGenVertexArrays(amount, intArray);
        glBindArrays(vertexIDsArray);
    }
    
    readObjIn() {
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
            std::cout << "line " <<  string2 << std::endl;
            
            std::regex pattern(R"(v\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]))");  //[0-9.+], + means digit or '.'
            

            std::smatch matches;   //an array that contains matched characters
            
            if(std::regex_match(string2, matches, pattern)) {
                std::cout << matches[0];
                std::cout << matches[1];
                std::cout << matches[2];
                std::cout << matches[3];
            }
            
                    
        }
            
        
        
    }
};

