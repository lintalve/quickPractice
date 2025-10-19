// Include standard OpenGL headers (for things like gl.h)
      // OpenGL extensions
#include "GL3/gl3.h"        // Core OpenGL 3.0+ headers

//Include windowing and utility libraries
#include <GLFW/glfw3.h>     // GLFW for window/context management
#include <GL/freeglut.h>    // FreeGLUT, only if needed

std::fstream myfile;

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
        //this object istringstream is to parse a string, not a file or keyboard input
         
        std::fstream myfile;
        std::string filePath = "cube.obj";
        
        myfile.open(filePath, std::ios::in);
        
        
        std::string text = "v 0.1 0.2 0.3 v 0.2 0.3 0.4 v 0.5 0.6 0.7" +
                           "v 0.8 0.9 0.11 v 0.12 0.13 0.14 v 0.15 0.16 0.17";
        std::string string;
        std::istringstream inStrStream(string);  //destination of the  >> stream
        
        char aChar;
        float firstFloat;
        float secondFloat;
        float thirdFloat;
              //std::getline() returns none void, so the
              //return value can be evaluated as true or false
        while(std::getline(text, string)) {  //while that function returns an object
            inStrStream >> aChar >> firstFloat >> secondFloat >> thirdFloat;
        }
        
        
    }
};
