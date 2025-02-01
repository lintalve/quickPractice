//: C16:TStackTest.cpp
//{T} TStackTest.cpp
#include "TStack_.h"
#include "require.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class X {
    public:
    virtual ~X() {
        cout << "~X " << endl;
    }
};
int main(int argc, char* argv[]) {
    requireArgs(argc, 1);
    // File name is argument                        //good code, problem solving code
    ifstream in(argv[1]);                           //not just level1 of listing the elements to learn them in order
    assure(in, argv[1]);
    Stack<string> textlines;
    string line;
    // Read file and store lines in the Stack:
    while(getline(in, line))                        //algorithic code //c-style code while(fgets(file.obj) != 0)
        textlines.push(new string(line));           //with the use of predeclared (out of scope) variables
    // Pop some lines from the stack:
    string* s;                                      //can be a global array, or a variable with static storage
    for(int i = 0; i < 10; i++) {
        if((s = (string*)textlines.pop())==0) break;     //rvalue assigned and than checked
        cout << *s << endl;                              //can be resolved above in a separate line
        delete s;
    }
    // The destructor deletes the other strings.
    // Show that correct destruction happens:
    Stack<X> xx;
    for(int j = 0; j < 10; j++) xx.push(new X);
} ///:~ 
