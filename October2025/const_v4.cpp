


struct MyClass {

    static const someConst1 = 34534;  //no storage
    static const someConst2 = 23454;
    static const someConst3 = 82376;
    static const someConst4 = 34521;
    
    const int myConst1 = 234;  //storage, read only
private:
    int someInt {};
    float someFloat {};
    double someDouble {};
public:
    //you are forced to add default constructor if you add your custom one, so
    MyCLass() : someInt(123), someFloat(123.456), someDouble(456.7890987) {}
    MyClass(int i, float f, double d) : someInt(i), someFLoat(f), someDouble(d) {}  //normal constractor
    
    //you have access to the private members of the instance  of the same type
    //from COpy constructors initialiser list
    MyClass(const MyCLass& other) : someInt(other.someInt),
                                            someFLoat(other.someFloat),
                                            someDouble(other.someDouble) {
        std::print("copy construction");
    }
    //copy operator=
    //Yes, you do have an access to te private member variables of the other intance of the same type minimum
    MyClass& operator=(const MyClass& other) {
        if(&other == this) return *this;
        someInt = other.someInt;
        someFLoat = other.someFloat;
        someDouble = other.someDouble;
        return *this;
    }
    //Move consttructor      //here you call copy-constructors
    MyClass(MyClass&& other) noexcept : someInt(other.someInt),
                                        someFloat(other.someFloat),
                                        someDouble(other.someDouble) {
        //leaveing moved from object in an empty state
        other.someInt = 0;
        other.someFloat = 0.0f;
        other.someDouble = 0.0;
    }
    ~MyClass() {}  //normal destructor, called in the end of the scope
                 //cosequentially for all local objects
};


int main() {
    
    MyCLass mc1;
    MyClass mc2 = mc1;  //Copy constructing, not Copy operator=
    MyClass mc3(mc1);
    return 0;
}
