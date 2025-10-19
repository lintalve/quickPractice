#include <cstdio>
#include <iostream>
#include <string>

class StringStack {
    static const int size = 36;
    const std::string* ptr_array[size] = {};  //initialises all to 0
    int index;
public:
    StringStack() : index(0) {
        puts("defaul consttructor");
    }
    void push(const std::string * s) {
        //see if we can access static variables from inside the function scope
        std::cout << 
        if(index < size) {
            ptr_array[index] = s;
            index++;
        }
            
    }
    const std::string* pop() {
        if(index > 0) {
            index--;
            const std::string* ptr = ptr_array[index];
            ptr_array[index] = nullptr;
            return ptr;
        }
        return 0;
    }
};

std::string iceCream[] = {
    "pralines & cream",
    "fudge ripple",
    "jamocha almond fudge",
    "wild mountain blackberry",
    "raspberry sorbet",
    "lemon swirl",
    "rocky road",
    "deep chocolate fudge" };

int main(int argc, const char* argv[]) {
    int array_size = sizeof(iceCream)/sizeof(*iceCream);
    StringStack ss;
    for(int i=0; i<array_size; i++) {
        ss.push(&(iceCream[i]));
    }
    const std::string* sp;
    while((sp = ss.pop()) != nullptr)
        std::cout << *sp << std::endl;
    
    return 0;
}

