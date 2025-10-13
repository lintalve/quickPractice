//: C16:TStack.h
// The Stack as a template
//So this is essencially a link list
//Okay, let's implement a link list
/*
 and than test it, use it
 */
#ifndef TSTACK_V2_H
#define TSTACK_V2_H

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

#endif // TSTACK_H ///:~

