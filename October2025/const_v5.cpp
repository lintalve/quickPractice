#include <print>
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
        std::print("default constructor call\n");
    }
    ~MyClass() {}
    static MyClass makeObject() {
        return MyClass();  //syntax for temporary object
    }
    int getData() const {
        return data;
    }
};
//######## FUNCTIONS ############
const MyClass makeMyClass() {   //return by value
    return MyClass();     // does not create and then move a temporary anymore (since C++17).
}

const MyClass makeConstMyClass() {
    return MyClass();
}

void printData1(const MyClass& myClass) {
    std::print("{}\n", myClass.getData());
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
    
    MyClass&& rrref = makeMyClass();
    
    std::print("{}\n", mc1.getData());
    std::print("{}\n", mc2.getData());
    std::print("{}\n", ref.getData());
    
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
    MyClass& rref = makeMyClass() = makeMyClass() = makeMyClass() = makeMyClass();
    
    return 0;
}
