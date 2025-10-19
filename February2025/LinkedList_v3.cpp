/*
 In this file, we're gonna separate the the logic of LinkedList
 core mechanism and additional functionality by using the inheritance.
 We'll extend simple LinkList with iterator and access methods relyed
 upon the counter.
 
 We use Base<T>::ValueType (or a similar alias) when we need to refer to the base class's template parameter separately from the derived class's template parameter
 */
template<typename T> class LinkList {
    struct Link{
        using theList = LinkList<T>::T
        Link* next {nullptr};
        T* data {nullptr};
    public:
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    }* head {nullptr};
public:       //syntax for member object initialisation
    LinkList() : head(nullptr, nullptr) {}
    LinkList(T* data) : head(data, nullptr) {}
    
    void push(T* data) {
        head = new Link(data, head);
        
    }
    T* pop() {
        if(head) {
            Link* currentLink = head;
            T* data = currentLink->data;
            head = currentLink->head
            delete currentLink; //deleting only current link, it doesn't spread to inside without a constructor
                                //and we have the pointer to the next link already
            return data;
        } else { throw std::out_of_range("nothing to pop, the list is empty"); }
        
    }
};
//we use LinkList<T> as a type of class, not type of an object
//as it were LinkList<int>, we use it with scope resolution operator
//to specify, to resolve the scope and to access inner scope
template<typename T> class LinkedList : public LinkList<T> {
    
    class iterator {
        LinkList<T>::Link& l; //just to use this syntax
        LinkList<T>& ll {};
    public:
        iterator(LinkList<T>& list) :
    };
    iterator begin() {
        return iterator();  //returning a nested class
    };
};
