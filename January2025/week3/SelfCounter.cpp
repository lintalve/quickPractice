//: C16:ValueStack.h
// Holding objects by value in a Stack
#include <iostream>
#include "require.h"

template<class T, int ssize = 100>
class Stack {
    // Default constructor performs object
    // initialization for each element in array:
T stack[ssize];
    int top;
public:
    Stack() : top(0) {}
// Copy-constructor copies object into array:
    void push(const T& x) {
        require(top < ssize, "Too many push()es");
        stack[top++] = x;
    }
    T peek() const { return stack[top]; }
    // Object still exists when you pop it;
    // it just isn't available anymore:
    T pop() {
        require(top > 0, "Too many pop()s");
        return stack[--top];
    }
};

//: C16:SelfCounter.h+8/877777



class SelfCounter {
    static int counter;
    int id;
public:
    SelfCounter() : id(counter++) {
        std::cout << "Created: " << id << std::endl;
    }
    SelfCounter(const SelfCounter& rv) : id(rv.id) {
        std::cout << "Copied: " << id << std::endl;
    }
    SelfCounter operator=(const SelfCounter& rv) {
        std::cout << "Assigned " << rv.id << " to " << id << std::endl;
        return *this;
    }
    ~SelfCounter() {
        std::cout << "Destroyed: "<< id << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const SelfCounter& sc){
        return os << "SelfCounter: " << sc.id;
    }
};

//: C16:SelfCounter.cpp {O}

int SelfCounter::counter = 0;
///:~ //:


#include "ValueStack.h"
#include "SelfCounter.h"
#include <iostream>
using namespace std;

int main() {
    Stack<SelfCounter> sc;
    for(int i = 0; i < 10; i++)
        sc.push(SelfCounter());
    // OK to peek(), result is a temporary:
    cout << sc.peek() << endl;
    for(int k = 0; k < 10; k++)
        cout << sc.pop() << endl;
} ///:~

