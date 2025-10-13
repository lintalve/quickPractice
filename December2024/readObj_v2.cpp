#include <iostream> //sream object that streams into or from an keyboard input
#include <sstream>  //stream object that streams into a string
#include <fstream>  //stream object that streams into and from a file
#include <cstdio>


int main(int argc, const char* argv[]) {
    
    std::string string; //string to stream into
    std::string text = "v 0.1 0.2 0.3\n v 0.4 0.5 0.6\n v 0.7 0.8 0.9\n v 0.11 0.12 0.13\n";
    std::istringstream iss; //stream object that streams into string
    char aChar;
    float float1;
    float float2;
    float float3;
    
    while(std::getline(iss, string)) {
        iss >> aChar >> float1 >> float2 >> float3;
    }
    
    std::cout << aChar << float1 << float2 << float3;
    
    return 0;
}
