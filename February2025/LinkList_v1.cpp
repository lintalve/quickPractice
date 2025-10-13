/*
 So, in this file we will try to create templatized linklist AND
 apply it to our strings and ifstream.
 That would simulate a working scenario of solving a task, a very simple
 string problem with custom made data structure. To apply the real strength of c++;
 
 Link has noconstructor to avoid recursive deletion all chain from the end towards
 the bbegining link.
 
 We could but we won't impement all the bells and whistles for this container
 The most impoortant part is to know and understand deeply and thorrouhly the mechanism
 of linked list
 */

#include <print>
#include <format>
#include <iostream>
#include <string>

#include <stdexcept>  // Required for std::out_of_range




template<typename T> class LinkedList {
    struct Link {  //let's keep it open for now
        Link* next {nullptr};
        T* data {nullptr};
        Link() {}                           //here goes new ptr
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
        //constructor would delete recursively all chain at once
        //so no constructor
        /*
         ~Link() {
            delete data;   //would delete the data, it happens not here, later on
            delete next;   //recursion, would stroll through the chain and would delete all
            //the chain from behind
        }
         */
    }* head {nullptr}; //a pointer to a variable of the nested class  Link* head;
    //it can directly use T* from the outer class without needing its own template parameters.
    int count {};
    class iterator {
        //I don't think you can have a reference, only const one
        //and traverse that container only
        const LinkedList& list;   //doesn't occupy space, free, doesn't bloat the iterator
        LinkedList::Link* local;  //something like "../Link"
        int counter {};
    public:
        iterator(LinkedList& ll) : local(ll.head) {}
        iterator(LinkedList& ll, int step) : list(ll), local(ll.head + step) {}
        T* operator*() {    //nested class can use outer class template type parameter
            return local->data;  //returns local->data
        }
        iterator& operator++() {
            if(local->head) {
                local++;
                counter++;
                return *this;
            }
            
        }
        iterator& operator++(int) {   //a convention in c++, errors otherwise!
            if(local->head) {
                ++local;
                ++counter;
                return *this;
            } else { throw std::out_of_range("Error message describing the issue"); }
            
        }
        iterator& operator--() {
            if(counter) {
                --local;
                --counter;
            } else { throw std::out_of_range("Error message describing the issue"); }
        }
        iterator& operator+(int step) {  //can be implemented as friend gloabl function
            if(list.count - counter >= step) {
                return iterator(list, step);
            } else { throw std::out_of_range("Error message describing the issue"); }
        }
        //return by reference to return itself, not a separate copy
        iterator& operator+=(int step) {
            if(list.count - counter >= step) {
                local+=step;
                return *this;
            } else { throw std::out_of_range("Error message describing the issue"); }
        }
        bool operator==(const iterator& it) const {
            returns (local == it.local) ? true : false;
        }
        bool operator!=(const iterator& it) const {
            returns (local != it.local) ? true : false;
        }
        bool operator>(const iterator& it) const {
            returns (local > it.local) ? true : false;
        }
        bool operator>=(const iterator& it) const {
            returns (local >= it.local) ? true : false;
        }
        bool operator<(const iterator& it) const {
            returns (local < it.local) ? true : false;
        }
        bool operator<=(const iterator& it) const {
            returns (local <= it.local) ? true : false;
        }
        //let's implement a printout of the it itself
        //appearantly you can't because you don't know the T, can't define << for every possible Type
        //that container might hold
        //friend std::ostream& operator<<(std::ostream& os, LinkedList::iterator it) {
        //    return os << counter;   //prints the iterator
        //}
    };
public:
    
    LinkedList() {}
    LinkedList(T* data) : head(new Link(data, nullptr)) {}
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator(*this);
    }
    void push(T* data) {
        head = new Link(data, head);
        count++;
    }
    
    T* pop() {
        if(!head) return nullptr;
        Link* currentHead = head;  //copys pointer to head into cH
        T* data = currentHead->data;
        head = currentHead->next;
        delete currentHead;    //no constructor call chain. //after updating the list structure
        count--;
        return data;
        
    }
    T* peek() {
        return head ? head->data : nullptr;
    }
    ~LinkedList() {
        while(head)
            delete pop();   //deletes only data pointer
    }                       //Link pointer is deleted inside pop()
    /*
    //almost the same implementation
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    */

};



int main(int argc, const char* argv[]) {

    LinkedList<std::string> stringsList;
    stringsList.push(new std::string("the first string"));    //error
    stringsList.push(new std::string("the second string"));    //error
    stringsList.push(new std::string("the third string"));    //error

    //for(int i=0; i<3; i++) std::print("{}\n", stringsList.pop());
    for(int i=0; i<3; i++) std::cout << *stringsList.pop() << std::endl;
    
    return 0;
}

