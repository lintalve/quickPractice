#include <cstdio>
#include <print>
#include <iostream>

/*
 This is an important file in it I try to comprehend internal workings of c++
 Rvalues and lvalues
 */

/*
| Type of reference | Can bind to                            | Notes                                        |
| ----------------- | -------------------------------------- | -------------------------------------------- |
|  T&               | **lvalues only**                       | Can’t bind to temporaries                    |
|  const T&         | **anything** (lvalue, xvalue, prvalue) | Extends lifetime of temporaries              |
|  T&&              | **rvalues only** (xvalue, prvalue)     | Does *not* extend lifetime beyond expression |
*/

class MyClass {
    int data {};
public:
    MyClass() : data(5) {
        std::cout << "default constructor call" << std::endl;
    }
    //Copy-constructor
    MyClass(const MyClass& other) : data(other.data) {
        std::cout << "Copy-constructor call" << std::endl;
    }
    //Copy-operartor=
    MyClass& operator=(const MyClass& other) {
        std::cout << "Copy-operator= call" << std::endl;
        if(&other == this) return *this;
        data = other.data;
        return *this;  //returns lvalue by reference
        //not by const reference to allow vec1 += vec2
    }
    //Move-constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        std::cout << "Move-constructor call" << std::endl;
    }
    MyClass(const MyClass&& other) noexcept : data(other.data) {
        std::cout << "Move-constructor call" << std::endl;
    }
    //Move-operator=
    MyClass& operator=(MyClass&& other) noexcept {
        std::cout << "Move-operator= call" << std::endl;
        data = other.data;
        other.data = 0;
        return *this;
    }
    ~MyClass() {
        std::cout << "default destructor call" << std::endl;
    }
    //Static function
    static MyClass makeObject() {
        return MyClass();  //syntax for temporary object
    }
    int getData() const {
        return data;
    }
    void mutate() { data++;}
};


//######## FUNCTIONS ############
MyClass makeMyClass() {   //return by value
    return MyClass();     // does not create and then move a temporary anymore (since C++17).
}

const MyClass makeConstMyClass() {
    return MyClass();
}

void printData1(const MyClass& myClass) {
    std::cout << myClass.getData() << std::endl;
}
//######### MAIN ###############
int main(int argc, const char* argv[]) {
    
    MyClass mc1 = MyClass::makeObject();  //syntax for creating a full object with temporary
    
    MyClass mc2 = makeMyClass();
    
    const MyClass& ref = makeMyClass();  //const reference to a temporary object, to extend the life time
                                     //of the temporary to the lifetime of the reference,
                                     //there for to the end of the scope
//    MyClass& ref1 = makeMyClass(); //ERROR: non-const lvalue reference
    MyClass();  //syntax for creating a temporary
    
    const MyClass&& rref = makeMyClass();
    
    std::cout << mc1.getData() << std::endl;
    std::cout << mc2.getData() << std::endl;
    std::cout << ref.getData() << std::endl;
    std::cout << rref.getData() << std::endl;
    
    printData1(MyClass()); //so what's going on is passing by const reference allows you
                           //to bind a temporary which is const to a const reference,
                           //extend the life of a temporary const object to the life of the reference
                           //and pass that reference to the function, which is not the case with the pointers
    const MyClass* mcpt1 = &mc2;
    printData1(*mcpt1);   //address of constified mc2 is dereferences, which yields full const object
                          //of which the reference is created, that is then passed into a function
    printData1(mc1);
    
    //prvalue, since c++17, special rules apply:
    //        -assignable
    //        -gets destroyed at the end of the line
    //        -is modifiable
    
    puts("######## move and copy operator=, returns an lvalue reference ###############");
    
    //Here  the operator= (the one and only) is binding, no operator callled, no return value
    //MyClass& ref1 = MyClass();  //ERROR: non-const lvalue reference to type 'MyClass' cannot bind to a temporary of type 'MyClass'
    //Here  the operator= returns *this, LValue!! not an rvalue
    MyClass& rrref = MyClass() = MyClass() = MyClass() = MyClass();  //c++11 lvalue
    rrref.mutate();
    puts("###############");
    MyClass rrrref = MyClass();  //copy ilision, only default constructor
    puts("############# function ################");
    //MyClass ref4 = makeMyClass() = makeMyClass() = makeMyClass() = makeMyClass();
    puts("#########  move  ############");
    
    std::cout << MyClass().getData() << std::endl;
    return 0;
}

