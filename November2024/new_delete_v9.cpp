/*
 In this file we will explore overloading of new and delete
 of new[] and delete[] global and for a particular class
 */
#include <iostream>
#include <exception>
#include <string>

class myException : public std::exception {
    std::string msg {};
public:
    myException(const std::string& message) : msg(message) {}  //for when you throw it
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class Passport {
    std::string id {};
    int when {};
    std::string whom {};
};
class DrivingLicense {};

class Person{
    std::string name;
    std::string surname;
    int age {};
    float height {};
    bool married {};
    Passport* pass {nullptr};
    DrivingLicense* dl {nullptr};
public:
    Person() {
        puts("Constructing a Person");
    }     //if you define a custom one, this one won;t be generated
    Person(const char* n, const char* sn) : name(n), surname(sn) {
        puts("Constructing a Person");
    }
    Person(const char* n, const char* sn, int a, float h, bool mar) : name(n), surname(sn), age(a), height(h), married(mar), pass(nullptr), dl(nullptr) {
        puts("Constructing a Person");
    }
    Person(const char* n, const char* sn, int a, float h, bool mar, Passport* p, DrivingLicense* d) : name(n),
    age(a), height(h), married(mar), pass(p), dl(d) {
        puts("Constructing a Person");
    }
    //copy constructor
    Person(const Person& p) {
        puts("Copy constructing a Person");
        name = p.name; //custom copy assingment operator
        surname = p.surname;
        age = p.age;
        height = p.height;
        married = p.married;
        pass = p.pass;
        dl = p.dl;
    }
    //copy assignment operator returns *this for the chain assignment
    Person& operator=(const Person& p) {
        puts("copy assigning a Person");
        //check for self assignment
        if(&p == this) return *this;
        name = p.name; //custom copy assingment operator
        surname = p.surname;
        age = p.age;
        height = p.height;
        married = p.married;
        pass = p.pass;
        dl = p.dl;
        return *this;
    }
    
    //Move constructor
    Person(Person&& p) noexcept : name(p.name), surname(p.surname), age(p.age), height(p.height),
        married(p.married), pass(p.pass), dl(p.dl) {
            puts("Move constructing a Person");
            //leaving moved from object in a valid empty state
            p.name = "";
            p.surname = "";
            p.age = 0;
            p.height = 0.0;
            p.married = false;
            p.pass = nullptr;
            p.dl = nullptr;
    }
    ~Person() {
        puts("destructing a Person");
        delete pass;
        delete dl;
    }
    //Move assignment operator
    Person& operator=(Person&& p) noexcept  {
        name = p.name;
        surname = p.surname;
        age = p.age;
        height = p.height;
        married = p.married;
        pass = p.pass;
        dl = p.dl ;
            //leaving moved from object in a valid empty state
            p.name = "";
            p.surname = "";
            p.age = 0;
            p.height = 0.0;
            p.married = false;
            p.pass = nullptr;
            p.dl = nullptr;
        return *this;
    }
        

    
    //METHODS
    Passport* get_pass() const {
        if(pass == nullptr) throw myException("Passport is not yet actualised");
        return pass;
    }
    DrivingLicense* get_license() const {
        if(dl == nullptr) throw myException("Driving license is not yet actualiser=d");
        return dl;
    }
    //NEW & DELETE
    void* operator new(size_t sz) {
        printf("allocating %zu byte for a Person\n", sz);
        void* m = malloc(sz);
        if(!m) throw std::bad_alloc();
        return m;
    }
    void* operator new[](size_t sz) {
        printf("allocating %zu byte for a Person");
        void* m = ::operator new[](sz);
        return m;
    }
    void operator delete(void* ptr) {
        puts("custom delete operator for a Person");
        free(ptr); //it happens after constructor is called
    }

    //std::ostream
    friend std::ostream& operator<<(std::ostream& os, Person& p) {
        return os << "Person: " << p.name << " " << p.surname << "\n"
        << "age: " << p.age << "\n" << "height: " << p.height << std::endl;
    }
};

int main() {
    Person* p1 = new Person("Volodymyr", "Hrudnytskyi");
    std::cout << *p1;
    try{
        p1->get_pass();
    } catch (const myException& e){
        std::cout << "The error is: " << e.what() << std::endl;
        //exit(1);
    }
    std::cout << "notherfucker" << std::endl;
    
    Person* p2 = new Person("Anna", "Subbotka");
    
    Person* p3 = p2; //Copy constructing
    Person* p4 {};
    p4 = p3;   //Copy assignment operator
    
    Person* p5 = new Person("Victor", "Pavlic");
    Person p6 = std::move(*p5);     //Move constructing
    std::cout << p6 << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    //delete p6;
    
    
    return 0;
}


