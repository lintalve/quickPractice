//: C16:TStack.h
// The Stack as a template
//So this is essencially a link list
//Okay, let's implement a link list
/*
 and than test it, use it
 */
#include "require.h"
#include <fstream>
#include <iostream>
#include <string>


class LinkList {
    class Link {
        float* data {nullptr};
        Link* nextNode {nullptr};
        
    public:
        //Link(float* dat, Link* nextN) : data(nullptr), Link(nullptr) {}
        Link(float* dat, Link* nextN)  {} //let it be ready here
    }* head;
    push(float* dat) {
        head = new Link(dat, head);
    }
    float* pop() const {
        Link* currentHead = head;
        float* data = currentHead->data;
        head = currentHead->head;
        delete currentHead;
        return data;
    }
    ~LinkList() {
        while(dead)
            delete pop();
    }
};




class X {
    public:
    virtual ~X() {
        cout << "~X " << endl;
    }
};
int main(int argc, char* argv[]) {
                          //good code, problem solving code
    ifstream infile("linklist.txt", "r");                           //not just level1 of listing the elements to learn them in order
    //assure(in, argv[1]);
    
    Stack<string> textlines;
    string line;
    // Read file and store lines in the Stack:
    while(std::getline(infile, line))                        //algorithic code //c-style code while(fgets(file.obj) != 0)
        textlines.push(new string(line));           //with the use of predeclared (out of scope) variables
    // Pop some lines from the stack:
    string* s;                                      //can be a global array, or a variable with static storage
    for(int i = 0; i < 10; i++) {
        if((s = (string*)textlines.pop())==0) break;     //ownership, you transfer the pointer to client from your data structure
        cout << *s << endl;                              //for client to take resposability
        delete s;
    }
    // The destructor deletes the other strings.
    // Show that correct destruction happens:
    Stack<X> xx;
    for(int j = 0; j < 10; j++) xx.push(new X);
    return 0;
} ///:~

