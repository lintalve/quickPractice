//: C16:TLinkList2.h
// Templatized LinkList with nested iterator
#ifndef TSTACK2_H
#define TSTACK2_H
template<typename T> class LinkList {
    struct Link {     //keep members open with struct
        T* data;
        Link* nextNode;
        Link(T* dat, Link* nxt) : data(dat), nextNode(nxt) {}
    }* Node;
public:
    LinkList() : Node(0) {}
    ~LinkList();
    void push(T* dat) {
        Node = new Link(dat, Node);   //pointer to a pointer to a pointer Link********
    }
    T* peek() const {
        return Node ? Node->data : 0;
    }
    T* pop();

    class iterator {        // Now define it
        LinkList::Link* p;
    public:
        iterator(const LinkList<T>& tl) : p(tl.Node) {}
        // Copy-constructor:
        iterator(const iterator& tl) : p(tl.p) {}
        // The end sentinel iterator:
        iterator() : p(nullptr) {}
        // operator++ returns boolean indicating end:
        bool operator++() {
            if(p->next) p = p->next;
            else p = 0;
            // Indicates end of list
            return bool(p);
        }
        bool operator++(int) { return operator++(); }
        T* current() const {
            if(!p) return 0;
            return p->data;
        }
        T* afterNextOne() const { return Node->Node->Node->data;}
        // Pointer dereference operator:
        T* operator->() const {
            require(p != 0, "PLinkList::iterator::operator->returns 0");
            return current();
        }
        T* operator*() const { return current(); }
        // bool conversion for conditional test:
        operator bool() const { return bool(p); }
        // Comparison to test for end:
        bool operator==(const iterator&) const {
            return p == 0;
        }
        bool operator!=(const iterator&) const {
            return p != 0;
        }
    };
    iterator begin() const { return iterator(*this); }
    iterator end() const { return iterator(); }
};
template<typename T> LinkList<T>::~LinkList() {
    while(Node)
        delete pop();
}
template<class T> T* LinkList<T>::pop() {
    if(Node == 0) return 0;
    T* result = Node->data;
    Link* oldHead = Node;
    Node = Node->next;
    delete oldHead;
    return result;
}
#endif // TSTACK2_H ///:~

using namespace std;
int main() {
    /*
    ifstream file("TStack2Test.cpp");
    assure(file, "TStack2Test.cpp");
    Stack<string> textlines;
    // Read file and store lines in the Stack:
    string line;
    while(getline(file, line))
        textlines.push(new string(line));
    int i = 0;
    // Use iterator to print lines from the list:
    Stack<string>::iterator it = textlines.begin();
    Stack<string>::iterator* it2 = 0;
    while(it != textlines.end()) {
        cout << it->c_str() << endl;
        it++;
        if(++i == 10) // Remember 10th line
            it2 = new Stack<string>::iterator(it);
    }
    cout << (*it2)->c_str() << endl;
    delete it2;
     */
    
    return 0;
} ///:~
