/*
 So, in this file we will try to create templatized linklist AND
 apply it to our strings and ifstream.
 That would simulate a working scenario of solving a task, a very simple
 string problem with custom made data structure. To apply the real strength of c++;
 */

#include <print>
#include <format>
#include <iostream>
#include <string>

template<typename T> class LinkList {
    struct Link {  //let's keep it open for now
        Link* next {nullptr};
        T* data {nullptr};
        Link() {}                           //here goes new ptr
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
        ~Link() {
            delete data;
            delete next;
        }
    }* head {nullptr}; //a pointer to a variable of the nested class  Link* head;
public:
    LinkList() {}
    LinkList(T* data) : head(new Link(data, nullptr)) {}
    void push(T* data) {
        head = new Link(data, head);
    }
    T* pop() {
        if(!head) return nullptr;
        Link* currentHead = head;
        T* data = currentHead->data;
        head = currentHead->next;
        delete currentHead;
        return data;
        
    }
    ~LinkList() {
        while(head)
            delete pop();
    }
};

int main(int argc, const char* argv[]) {
    std::string str1 = "the first string";
    std::string str2 = "the second string";
    std::string str3 = "the third string";
    LinkList<std::string> stringsList;
    stringsList.push(&str1);     //error
    stringsList.push(&str2);
    stringsList.push(&str3);
    //for(int i=0; i<3; i++) std::print("{}\n", stringsList.pop());
    for(int i=0; i<2; i++) std::print("{}\n", *stringsList.pop());
    
    return 0;
}
