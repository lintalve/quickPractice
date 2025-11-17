#include <iostream>

/*
why copy operator= returns non-const reference
b1 = b2;    // okay
b1 = b2 = b3;  // still okay
(b1 = b2) = b3;  // error: left operand is const
*/


class Entity {
    static constexpr const char*  class_name = "Entity";
    static int count;
    //state variables
    const double value;
    int someInt;
    std::string name;
public:
    Entity();
    Entity(int i, float fl);
    Entity(const Entity& e);
    //the assigned object is meant to remain modifiable after the assignment expression
    //that is why not const reference
    Entity& operator=(const Entity& e);
    //Entity(Entity&& e) noexcept;
//Methods
    Entity& modify(int i);
    int getInt() const;
    std::string getName() const;

    
    ~Entity();
};
//################# STATIC ###########################//
int Entity::count = 0;

//################# CONSTRUCTORS OPERATORS ################################//
Entity::Entity() : someInt(0), value(0.0) {
    std::cout << "Default-constructor on" << std::endl;
    count++;
    //name = class_name + "_" + std::stoi(count);
    name.append(class_name).append("_").append(std::to_string(count));
}
Entity::Entity(int i, float fl = 0.0) : someInt(i), value(fl) {
    count++;
    //name = class_name + "_" + std::stoi(count);
    name.append(class_name).append("_").append(std::to_string(count));
}
Entity::Entity(const Entity& e) : someInt(e.someInt), value(e.value)  {
    count++;
    //name = class_name + "_" + std::stoi(count);
    name.append(class_name).append("_").append(std::to_string(count));
    std::cout << "Copy-constructor on" << name << std::endl;
}
Entity& Entity::operator=(const Entity& e) {
    std::cout << "Copy-operator= on " << name << std::endl;
    if(&e == this) return *this;
    someInt = e.someInt;
    return *this;
}
Entity::~Entity() {}



Entity& Entity::modify(int i = 5) { 
    someInt+=i;
    return *this;
 }
int Entity::getInt() const { return someInt; }
std::string Entity::getName() const { return name; }

std::ostream& operator<<(std::ostream& os, const Entity& e) {
    os << "objects is " << e.getName() << ", state is " << e.getInt();
    return os;
}

int main(int argc, const char* argv[]) {
    Entity e1;    //default constructor
    
    Entity e2 = Entity();   //Copy constructor
    std::cout << "#########################3" << std::endl;
    Entity e3(234, 4.564);
    //e3.modify().modify();
    std::cout << "#########################3" << std::endl;
    e2 = e3;    //copy operator
    std::cout << e3 << std::endl;
    e2.modify().modify().modify();   //return non-const lvalue reference to self
    std::cout << e2 << std::endl;
    Entity e4(e3);   //classic copy-constructor
    return 0;
}