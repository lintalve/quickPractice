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
    const char* name {};
    const char* surname {};
    int age {};
    float height {};
    bool married {};
    Passport* pass {nullptr};
    DrivingLicense* dl {nullptr};
public:
    Person() {}     //if you define a custom one, this one won;t be generated
    Person(const char* n, int a, float h, bool mar) : name(n), age(a), height(h), married(mar), pass(nullptr), dl(nullptr) {}
    Person(const char* n, int a, float h, bool mar, Passport* p, DrivingLicense* d) : name(n),
    age(a), height(h), married(mar), pass(p), dl(d) {}
    
    Passport* get_pass() const {
        if(pass == nullptr) throw myException("Passport is not yet actualised");
        return pass;
    }
    DrivingLicense* get_license() const {
        if(dl == nullptr) throw myException("Driving license is not yet actualiser=d");
        return dl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << "Person: " << p.name << " " << p.surname << std::endl
        << "age: " << p.age << std::endl << "height: " << p.height << std::endl;
    }
};

int main() {
    Person* p1 = new Person;
    //std::cout << *p1;
    try{
        p1->get_pass();
    } catch (const myException& e){
        std::cout << "The error is: " << e.what() << std::endl;
        exit(1);
    }
    std::cout << "notherfucker" << std::endl;
    
    return 0;
}
