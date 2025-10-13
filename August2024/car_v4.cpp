#include <iostream>
#include <string>
#include <OpenGL/gl.h>  // for OpenGL functions
#include <OpenGL/glu.h> // for OpenGL utility functions
#include <random>
#include <ctime>

class Object {
    int someInt{};
    std::string someString{};
public:
    
};


typedef enum Color {
    RED = 0,
    GREEN,
    BLACK,
    WHITE,
    BLUE,
    COUNT  //special value for total count - 1;
} Color;

Color getRandomColor() {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr))); // Seed the RNG
    std::uniform_int_distribution<int> dist(0, COUNT - 1); // Generate random index
    return static_cast<Color>(dist(rng)); // Cast to enum type
}



class Wheel {
    double radius {11 * 2.54};
    double distance {};
public:
    void d_count(double time) {
        double theta {1.0};
        distance = theta * radius * time;
    }
    double get_distance() const { return distance; }
};


class Window {
    bool closed{};
public:
    Window() : closed(true) {
        std::cout << "Window Default constructor" << std::endl;
    }
    
    //no need for custom copy constructor, bitwise copying is fine
    //no need for custom copy assignment operator, bitwise copying is fine
    //no need move?? pedantic approach says yes
    //need Copy constructor
    Window(const Window& w) {
        std::cout << "Window Copy-constructor" << std::endl;
    }
    Window& operator=(const Window& w) {
        std::cout << "Window Copy-assignment operator" << std::endl;
        if(&w == this) return *this;
        closed = w.closed;
        return *this;
    }
    Window(Window&& w) noexcept {
        std::cout << "Window Move-constructor" << std::endl;
        closed = w.closed;
        w.closed = true; //zum beischpiel
    }
    Window& operator=(Window&& w) noexcept {
        std::cout << "Window Move-assignment operator" << std::endl;
        closed = w.closed;
        w.closed = false; //zum beischpiel
        return *this;
    }
    //no need for custom destructor, no resources
    void close() { closed = true; }
    void open() { closed = false; }
    bool get_closed() const {return closed;}
};

class Door {
    Window* win {nullptr};
    //class has pointer, so it needs custom 6 functions
    bool closed{};
    //shouldn't be public, it'll leave the object empty
    //Door() {}  //for a dynamic array
public:
    Door() : win(new Window()), closed(true) {
        std::cout << "Door default Constructor" << std::endl;
        //win = new Window;
        //closed = true;
    }  //for a dynamic array
    Door(Window* w) : win(w), closed(true) {
        std::cout << "Door parametrized Constructor" << std::endl;
    }
    //Need custom copy constructor to avoid the stuation
    //where the copied pointer points to the same window
    
    //Yes, the constructor initializer list does have access
    //to private members of the passed const Door& d object,
    //provided that d is of the same class type as the one being constructed.
    Door(const Door& d) : win(new Window(*d.win)), closed(d.closed) {
        std::cout << "Door Copy-constructor" << std::endl;
    }
    //Copy assignment operator
    Door& operator=(const Door& d) {
        std::cout << "Door Copy-assignment operator" << std::endl;
        win = new Window(*d.win); //relies on Window copy constructor
        closed = d.closed;
        return *this;
    }
    //Move constructor
    Door(Door&& d) noexcept : win(new Window(*d.win)), closed(d.closed) {
        std::cout << "Door Move-constructor" << std::endl;
        //std::cout << "##############" << std::endl;
        //same rule, as long is object is the same Type
        //as the constructing object, private parts are accessable
        //leave moveed from obj in empty valid state
        d.win = nullptr;
        closed = false;
    }
    //Move assignment operator
    Door& operator=(Door&& d) noexcept {
        std::cout << "Door Move-assignment operator" << std::endl;
        win = new Window(*d.win);
        closed = d.closed;
        //leave...
        d.win = nullptr;
        d.closed = false;
        return *this;
    }
    ~Door() {
        delete win;
    }
    void openWindow() { win->close(); }
    void closeWindow() { win->open(); }
    void openDoor() { closed = false; }
    void closeDoor() { closed = false; }
    bool is_closed() const { return closed; }
};

class Body {
    //CONSTRUCTORS FOR THESE ARE AUTOMATICALLY CALLED BY THE COMPILER
    //IF YOU DON'T CALL THEM EXXPLICITLY IN THE !!!CONSTRUCTOR INITIALISER LIST OR With {}
    Door rightFront_d {};  // !!!Thus you can skip initialisation in Constructor initialisation list or override it there
    Door leftFront_d {};  // !!!Thus you can skip initialisation in Constructor initialisation listt or override it there
    Door rightRear_d {};  // !!!Thus you can skip initialisation in Constructor initialisation listt or override it there
    Door leftRear_d {};  // !!!Thus you can skip initialisation in Constructor initialisation listt or override it there
    Door rear_d {};  // !!!Thus you can skip initialisation in Constructor initialisation listt or override it there
    //PSEUDO-CONSTRUCTORS FOR THESE YOU CAN CALL IN THE !!!BODY!!! OF THE CONSTRUCTOR!!!
    Window* front_w {nullptr};
    Window* rear_w {nullptr};
    
    Wheel* rightFront_w {nullptr};
    Wheel* leftFront_w {nullptr};
    Wheel* rightRear_w {nullptr};
    Wheel* leftRear_w {nullptr};
public:         //No you can skip in CIL initialisation
    Body() { //: rightFront_d(), leftFront_d(), rightRear_d(), leftRear_d(), rear_d() {
        std::cout << "Body Default constructor" << std::endl;
        //rightFront_d = Door();  //Copy Window constructor=>Default Door constructor (temporary object) => Move Door operator=!!
        //leftFront_d = Door();   //Copy Window constructor=>Default Door constructor (temporary object) => Move Door operator=!!
        //rightRear_d = Door();   //Copy Window constructor=>Default Door constructor (temporary object) => Move Door operator=!!
        //leftRear_d = Door();    //Copy Window constructor=>Default Door constructor (temporary object) => Move Door operator=!!
        //rear_d = Door();        //Copy Window constructor=>Default Door constructor (temporary object) => Move Door operator=!!
        std::cout << "Body after doors constructor" << std::endl;
        Window* front_w = new Window();
        Window* rear_w = new Window();
        std::cout << "Body after windows constructor" << std::endl;
        Wheel* rightFront_w = new Wheel();
        Wheel* leftFront_w = new Wheel();
        Wheel* rightRear_w = new Wheel();
        Wheel* leftRear_w = new Wheel();
        std::cout << "Body after Wheels constructor" << std::endl;
    }
    Body(const Door& rFront_d,   //Doors have prvate default constructor
         const Door& lFront_d,
         const Door& rRear_d,
         const Door& lRear_d,
         const Door& re_d,
         
         Window* frnt,
         Window* rear,
         
         Wheel* rFront_w,
         Wheel* lFront_w,
         Wheel* rRear_w,
         Wheel* lRear_w)
    : rightFront_d(rFront_d),
    leftFront_d(lFront_d),
    rightRear_d(rRear_d),
    leftRear_d(lRear_d),
    rear_d(re_d),
    
    front_w(frnt),
    rear_w(rear),
    
    rightFront_w(rFront_w),
    leftFront_w(lFront_w),
    rightRear_w(rRear_w),
    leftRear_w(lRear_w) {
        std::cout << "Body parametrised constructor" << std::endl;
    }
    Body(const Door& rFront_d,   //Doors have prvate default constructor
         const Door& lFront_d,
         const Door& rRear_d,
         const Door& lRear_d,
         const Door& re_d)
    
    : rightFront_d(rFront_d),
    leftFront_d(lFront_d),
    rightRear_d(rRear_d),
    leftRear_d(lRear_d),
    rear_d(re_d)
    
    {
        std::cout << "Body parametrised constructor" << std::endl;
        front_w = new Window;
        rear_w = new Window;
        
        rightFront_w = new Wheel;
        leftFront_w = new Wheel;
        rightRear_w = new Wheel;
        leftRear_w = new Wheel;
    }
    //Copy constructor  relies on Door copy constructor
    Body(const Body& b) : rightFront_d(b.rightFront_d), leftFront_d(b.leftFront_d),
    rightRear_d(b.rightRear_d), leftRear_d(b.leftRear_d) {
        std::cout << "Body Copy-constructor" << std::endl;
        front_w = new Window(*b.front_w);
        rear_w = new Window(*b.rear_w);
        
        rightFront_w = new Wheel(*b.rightFront_w);
        leftFront_w = new Wheel(*b.leftFront_w);
        rightRear_w = new Wheel(*b.rightRear_w);
        leftRear_w = new Wheel(*b.leftRear_w);
    }
    //Copy assignmment operator
    Body& operator=(const Body& b) {
        std::cout << "Body Copy-assignment operator" << std::endl;
        rightFront_d = b.rightFront_d;  //requires Door copy assignment operator
        leftFront_d = b.leftFront_d;
        rightRear_d = b.rightRear_d;
        leftRear_d = b.leftRear_d;
        rear_d = b.rear_d;
        
        front_w = new Window(*b.front_w);
        rear_w = new Window(*b.rear_w);
        
        rightFront_w = new Wheel(*b.rightFront_w);
        leftFront_w = new Wheel(*b.leftFront_w);
        rightRear_w = new Wheel(*b.rightRear_w);
        leftRear_w = new Wheel(*b.leftRear_w);
        return *this;
    }
    //Move Constructor
    Body(Body&& b) noexcept : rightFront_d(b.rightFront_d), leftFront_d(b.leftFront_d),
    rightRear_d(b.rightRear_d), leftRear_d(b.leftRear_d) {
        std::cout << "Body Move-constructor" << std::endl;
        front_w = new Window(*b.front_w);
        rear_w = new Window(*b.rear_w);
        
        rightFront_w = new Wheel(*b.rightFront_w);
        leftFront_w = new Wheel(*b.leftFront_w);
        rightRear_w = new Wheel(*b.rightRear_w);
        leftRear_w = new Wheel(*b.leftRear_w);
    }
    //Move-assignment operator
    Body& operator=(Body&& b) noexcept  {
        std::cout << "Body Move-assignment operator" << std::endl;
        rightFront_d = b.rightFront_d;
        leftFront_d = b.leftFront_d;
        rightRear_d = b.rightRear_d;
        leftRear_d = b.leftRear_d;
        
        front_w = new Window(*b.front_w);
        rear_w = new Window(*b.rear_w);
        
        rightFront_w = new Wheel(*b.rightFront_w);
        leftFront_w = new Wheel(*b.leftFront_w);
        rightRear_w = new Wheel(*b.rightRear_w);
        leftRear_w = new Wheel(*b.leftRear_w);
        //Leaving the moved-from object in valid empty state
        
        b.rightFront_d.closeDoor();
        b.rightFront_d.closeWindow();
        b.leftFront_d.closeDoor();
        b.leftFront_d.closeWindow();
        b.rightRear_d.closeDoor();
        b.rightRear_d.closeWindow();
        b.leftRear_d.closeDoor();
        b.leftRear_d.closeWindow();
        b.rear_d.closeDoor();
        b.rear_d.closeWindow();
        return *this;
    }
    ~Body() {
        std::cout << "Body destructor" << std::endl;
        delete front_w;
        delete rear_w;
        
        delete rightFront_w;
        delete leftFront_w;
        delete rightRear_w;
        delete leftRear_w;
    }
    friend std::ostream& operator<<(std::ostream& os, const Body& b) {
        return os << "Body has 5 doors, 4 wheels and 6 windows" << std::endl;
    }
    
};

class Vehicle {
    class LicPlate {
    public:
        //let it be public here and private further
        //so these (const char* string literals) are
        //stored in read-only area of the memory
        //deleting them is undefined behaviour
        Color color {};
        const char* number {nullptr};

        LicPlate() {
            std::cout << "LicPlate Default constructor" << std::endl;
        };
        LicPlate(const char* num) : number(num) {
            std::cout << "LicPlate Parametrized constructor" << std::endl;
            color = getRandomColor();
        }
        void set_number(const char* num) { number = num; }
        const char* get_number() const { return number; }
        Color getColor() const { return color; }
    }lp;
    //If MyClass does not have a default constructor, and the braces are empty (i.e., {}),
    //value-initialization occurs, which means that obj is initialized to its default value
    //(for example, zero for primitive types or calling the default constructor for class members).
    //LicPlate lp {};  //CALLS the defaault constructor right there!!
    float top_speed {};
public:
    Vehicle() : lp("DE93745"), top_speed(230.5f) {
        std::cout << "Vehicle Default constructor" << std::endl;
    }
    void set_lp(const char* num) { lp.number = num; }
    const char* get_lp() const { return lp.number; }
};

class Car : public Vehicle {
    //COMPOSITION
    Body body;
    
public:
    //Car calls member object body constructor in its init-list
    Car() : body() { std::cout << "Car Default constructor" << std::endl; }
    void setNumber(const char* number) {
        Vehicle::set_lp(number);
    }
    
                        
};

//Global functions:
Car modifyCar(Car c, const char* number) {
    c.setNumber(number);
    return c;
}
Car getCar(const char* number) {
    Car c;
    return c;
}
/*
Car&& returnCar(const char* number = "UA23745") {
    
    //return Car();  //WARNING:: returns rvalue but not a reference to it
    //return std::move(Car());   //UNDEFINED BEHAVIOUR, compiler destroys temp Car() object before returning
    Car c;
    return std::move(c);
}
*/
int main(int argc, const char* argv[]) {
    //Door rFd(new Window());  //default constructor
    //Door lFd(new Window());
    //Door rRd(new Window());
    //Door lRd(new Window());
    
    //Window* front = new Window; //also default constructor
    //Window* rear = new Window;
    
    //Body bd(rFd, lFd, rRd, lRd, Door());
    
    //Car car1;
    Body bd1;
    
    
    
    // !!!VERY IMPORTANT !!! - next lines are very important
    std::cout << "##############################" << std::endl;
    Door myDoor;  //When in function, DEFAULT CONSTRUCTOR IS CALLED!! = Window default constructor, Door default constructor
    myDoor = Door(); //It would be copy if not temporary object
                     //due to embedded Window member user-defined object, it's constructor is AUTOMATICALLY if not
                     //explicitly called in Constructor Initializer List, then Door(), then mo
    std::cout << "##############################" << std::endl;
    /*
    ##############################
    Window Default constructor
    Door default Constructor
    Window Default constructor
    Door default Constructor
    Door Move-assignment operator
    ##############
    Window Copy-constructor
     ##############################
    */
    //Car car1;
    //Car car2 = modifyCar(car1, "UA24564");
    
    
    return 0;
}



