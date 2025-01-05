#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

int main(int argc, const char* argv[]) {
    std::string text = "v 0.1 0.2 0.3\n v 0.4 0.5 0.6\n v 0.7 0.8 0.9\n v 0.11 0.12 0.13";
    std::string string;  //string to stream into
    std::istringstream inputStringStream(text);
    
    char aChar;
    float firstFloat;
    float secondFloat;
    float thirdFloat;
    
    while(std::getline(inputStringStream, string))  {
        inputStringStream >> aChar >> firstFloat >> secondFloat >> thirdFloat;
    }
    
    std::cout << aChar << firstFloat << secondFloat << thirdFloat;
    //printf("%c %f %f %f", aChar, firstFloat, secondFloat, thirdFloat);
    //std::getline(inputStringStream, string);
    //std::cout << string;
    
    return 0;
}
