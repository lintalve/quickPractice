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
#include <exception>

class myException : std::exception {
    std::string message;
public:
    myException(const char* msg) : message(msg) {}
    const char* what() const noexcept {
        return message.c_str();
    }
};

template<typename T>
class LinkList {
    
    struct Link {    //struct to reach it from outer class
        T* dataItem {nullptr};
        Link* nextNode {nullptr};
        
    
        //Link(float* dat, Link* nextN) : dataItem(nullptr), Link(nullptr) {}
        Link(T* dat, Link* nextN) : dataItem(dat), nextNode(nextN) {} //let it be ready here
    }* head;
    short i {};
protected:
    int index() const { return i; }
public:
    
    LinkList() : head(nullptr) {}
    void push(T* dat) {
        head = new Link(dat, head);
        i++;
    }
    T* pop() {
        if(head) {
            Link* temp = head;
            T* dataItemPtr = temp->dataItem;
            head = temp->nextNode;
            delete temp;
            i--;
            return dataItemPtr;
        } else throw myException("nothing to return from link list");
    }
T* peek() {
    if(head){
        return head->dataItem;
    } else throw myException("nothing to return from link list");
    }
    ~LinkList() {
        while(head)
            delete pop();
    }
};


int main(int argc, char* argv[]) {
    
    std::ifstream file("linklist.txt");
    LinkList<std::string> strings;
    std::string line;
    
    // Read file and store lines in the Stack:
    int i {};
    while(std::getline(file, line)) {                        //algorithic code
        strings.push(new std::string(line));           //with the use of predeclared
        i++;
    }
    //std::string* s;
    int j {0};
    while(j < 4) {
        try {
            std::cout << *(strings.pop()) << std::endl;
        } catch (const myException& e) {
            std::cout << e.what() << std::endl;
        }
        j++;
    }
    /*
    string* s;                                      //can be a global array, or a variable with static storage
    for(int i = 0; i < 10; i++) {
        if((s = (string*)textlines.pop())==0) break;     //ownership, you transfer the pointer to client from your dataItem structure
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




