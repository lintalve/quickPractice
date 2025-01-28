//: C16:TStack.h
// The Stack as a template
/*
 Very unusual  data structure with more advanced and complicated
 combination of simple concepts
 */

template<class T>
class Stack {
    
    struct Link {
        T* data;
        Link* next;   //this is a pointer to a separate copy of the class
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    }* head;   //Head always points to the top most link in the chain, due to the main functions
               //such as push and pop,
    public:
    Stack() : head(nullptr) {}   //initialising to default state
    ~Stack(){
        while(head)
            delete pop();
    }
    void push(T* dat) {     //head from inside, from private
        head = new Link(dat, head);   //every Link object holds the pointer only to the next one,
                                      //so in order to get the desired node, you have to get to it one by one
                                      //so you have to get, verify with if() the link is yours or not
                                      //allocates, initialis
                                      //we can ry and rewrite it in c
    }
    T* peek() const {
        return head ? head->data : nullptr;   //so you could use it with while() or if()
    }
    T* pop(){
        if(head == 0) return nullptr;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }
};



using namespace std;

class X {
    public:
    virtual ~X() {
        cout << "~X " << endl;
    }
};
int main(int argc, char* argv[]) {
    requireArgs(argc, 1);
    // File name is argument
    ifstream in(argv[1]);
    assure(in, argv[1]);
    
    Stack<string> textlines;  //this is the stack from above with the links
    
    string line;
    // Read file and store lines in the Stack:
    while(getline(in, line))  //while this std::getline() retrurns something, this is THE Coding
                              //this is exacoly c style programming, only not with while(fgetc)
        textlines.push(new string(line));
    // Pop some lines from the stack:
    string* s;
    for(int i = 0; i < 10; i++) {
        if((s = (string*)textlines.pop())==0) break;        //again, algorithm with data structure, with encapsulated
        cout << *s << endl;                                 //so you need to study algorithms before openGl 
        delete s;
    }
    // The destructor deletes the other strings.
    // Show that correct destruction happens:
    Stack<X> xx;
    for(int j = 0; j < 10; j++) xx.push(new X);
} ///:~
