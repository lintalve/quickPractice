#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, const char* argv[]) {
    
    string someString = "alsdkjh qwer oiuoi";
    
    string additional = "additional";
    string another = "another";
    
    
    
    stringstream ss(someString, ios::out | ios::out);
    
    ss << "aaaaaa " ;
    
    cout << ss.str();
    
    string path = "test2.obj";
    fstream fstream(path, ios::in | ios::out);
    
    if(fstream.is_open()) {
        fstream << "111111111111111111111" << endl;
        fstream << "111111111111111111111" << endl;
        fstream << "111111111111111111111" << endl;
        fstream << "111111111111111111111" << endl;
        fstream << "111111111111111111111" << endl;
        fstream << "111111111111111111111" << endl;
        string smString;
        smString = fstream.rdbuf();
        cout << smString;
        fstream.close();
    } else {
        cout << "file is not open" << endl;
    }
    
    return 0;
}
