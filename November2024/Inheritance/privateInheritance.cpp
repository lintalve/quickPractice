//: privateInheritance.cpp

class Pet { public:
    char eat() const { return 'a'; }
    int speak() const { return 2; }
    float sleep() const { return 3.0; }
    float sleep(int) const { return 4.0; }
};

class Goldfish : Pet {
    // Private inheritance
public:
    Pet::eat;
    // Name publicizes member
    Pet::sleep;
    // Both overloaded members exposed
};

int main() {
    Goldfish bob;
    bob.eat();
    bob.sleep();
    bob.sleep(1);
    // ! bob.speak();  // Error: private member function
} ///:~
