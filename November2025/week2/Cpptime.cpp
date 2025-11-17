//: C09:Cpptime.cpp
// Testing a simple time class 
#include "Cpptime.hpp" 
#include <iostream> 
using namespace std;

int main(int argc, const char* argv[]) {
    Time start;
    for(int i = 1; i < 1000; i++) {
        cout << i << ' ';
        if(i%10 == 0) cout << endl;
    }
    Time end;
    cout << endl;
    cout << "start = " << start.ascii();
    cout << "end = " << end.ascii();
    cout << "delta = " << end.delta(&start);
    return 0;
 } ///:~