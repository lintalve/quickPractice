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
    struct Link {    //struct to reach it from outer class
        float* data {nullptr};
        Link* nextNode {nullptr};
        
    
        //Link(float* dat, Link* nextN) : data(nullptr), Link(nullptr) {}
        Link(float* dat, Link* nextN) : data(dat), nextNode(nextN) {} //let it be ready here
    }* head;
public:
    LinkList() : head(nullptr) {}
    void push(float* dat) {
        head = new Link(dat, head);
    }
    float* pop() {
        if(head == nullptr) return nullptr;
        
        float* data = head->data;   //
        Link* headholder = head;   //holding current  head
                                    //for further deletion
        head = head->nextNode;  //setting head to next one from deep
        delete headholder;
        return data;
    }
    float* peek() {
        return head->data;
    }
    ~LinkList() {
        while(head)
            delete pop();
    }
};


int main(int argc, char* argv[]) {
    
    LinkList floats;
    float f1 {};
    float ff[] = {12.345, 43.675, 26.987, 76.435, 43.164, 42.375};
    // Read file and store lines in the Stack:
    int i {};
    while( i < sizeof(ff)/sizeof(*ff)) {                        //algorithic code //c-style code while(fgets(file.obj) != 0)
        floats.push(new float(ff[i]));           //with the use of predeclared (out of scope) variables
        i++;
    }
    for(int i=0; i<sizeof(ff)/sizeof(*ff); i++) {
        std::cout << *(floats.pop()) << std::endl;
        //std::cout << i << std::endl;
    }
    /*
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
     (f1 = *ff != 0.0) &&
    */
    return 0;
     
    
} ///:~



