//: C16:TStack.h
// The Stack as a template
/*
 Very unusual  data structure with more advanced and complicated
 combination of simple concepts
 */
#ifndef TSTACK_H
#define TSTACK_H
template<class T>
class Stack {
    
    struct Link {
        T* data;
        Link* next;   //this is a pointer to a separate copy of the class
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    }* head;
    
    public:
    Stack() : head(nullptr) {}   //initialising to default state
    ~Stack(){
        while(head)
            delete pop();
    }
    void push(T* dat) {     //head from inside, from private
        head = new Link(dat, head);   //order of operations is decisive
                                      //so first compiler reads the expression
                                      //it reads the head pointer and pass it into the constructor
                                      //allocates, initialis
                                      //we can ry and rewrite it in c
    }
    T* peek() const {
        return head ? head->data : 0;
    }
    T* pop(){
        if(head == 0) return 0;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }
};

#endif // TSTACK_H ///:~

