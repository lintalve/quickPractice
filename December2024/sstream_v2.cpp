#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, const char* argv[]) {
    
    string someString = "aasdfas asdfas qwer qwer qwe asdfm qasdfasfd";
    string destination;
    //stringstream ss(destination, ios_base::out);  //only 3 constructors for this stream
    stringstream ss;  //only 3 constructors for this stream
    
    ss << someString << endl;
    
    cout << ss.str();
    return 0;
}
