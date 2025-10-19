//: C16:TStack.h
// The Stack as a template
//So this is essencially a link list
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
    Stack() : head(0) {}
    
    void push(T* data) {
        head = new Link(data, head);     //hidden implementation
                                        //undelying implementation is hidden
    }
    T* peek() const {
        return head ? head->data : nullptr;   //nullptr evaluates as false
    }
    T* pop(){
        if(head == nullptr) return 0;      //nullptr can't be converted into bool implicitly, so this line is not if(!head)
        Link* currentHead = head;     //to hold current head separately
        T* result = head->data;
        head = head->next;       //getting the next head through cuurent
        delete currentHead;   //relasing current head memory
        return result;
    }
    ~Stack(){
        while(head)           //brilliant
            delete pop();     //brilliant
    }
};

#endif // TSTACK_H ///:~
