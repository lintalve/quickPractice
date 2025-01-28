//: C16:SelfCounter.cpp

#include "ValueStack.h"
#include <iostream>

class SelfCounter {
    static int counter;
    int id;
public:
    SelfCounter() : id(counter++) {
        std::cout << "Created: " << id << std::endl;
    }
    SelfCounter(const SelfCounter& rv) : id(rv.id){
        std::cout << "Copied: " << id << std::endl;
    }
    SelfCounter operator=(const SelfCounter& rv) {
        std::cout << "Assigned " << rv.id << " to " << id << std::endl;     return *this;
    }
    ~SelfCounter() {
        std::cout << "Destroyed: "<< id << std::endl;
    }
    friend std::ostream& operator<<( std::ostream& os, const SelfCounter& sc){
        return os << "SelfCounter: " << sc.id;
    }
};
#endif // SELFCOUNTER_H

///:~ //: C16:SelfCounter.cpp {O}
///
 #include "SelfCounter.h"
int SelfCounter::counter = 0; ///:~ //: C16:ValueStackTest.cpp //{L} SelfCounter #include "ValueStack.h" #include "SelfCounter.h" #include <iostream> using namespace std; int main() {   Stack<SelfCounter> sc;   for(int i = 0; i < 10; i++)     sc.push(SelfCounter());   // OK to peek(), result is a temporary:   cout << sc.peek() << endl;   for(int k = 0; k < 10; k++)     cout << sc.pop() << endl; } ///:~
