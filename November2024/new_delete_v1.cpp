#include <iostream>
#include <initializer_list>


static const int size = 64;

struct Vector3 {
    double x{};
    double y{};
    double z{};
    Vector3() {} //is here for the array
    Vector3(double a, double b, double c) : x(a), y(b), z(c) {}
    Vector3(float a, float b, float c) {
        std::cout << "constructing a Vector3" << std::endl;
        x = static_cast<double>(a);
        y = static_cast<double>(b);
        z = static_cast<double>(c);
    }
    //copy consntructor needed with pointers, otherwise generated
    Vector3(const Vector3& v) {
        std::cout << "copy constructing" << std::endl;
        x = v.x;
        y = v.y;
        z = v.z;
    }
    //Copy assignment operator
    Vector3& operator=(const Vector3& v) {
        std::cout << "copy assigning a Vector3" << std::endl;
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    ~Vector3() {
        std::cout << "destructing a Vector3" << std::endl;
    }
};

int main(int argc, const char* argv[]) {
    
    Vector3* v1 = new Vector3;
    Vector3* v2 = new Vector3(2.5, 5.5, 3.5);
    Vector3* const vArray = new Vector3[size]; //must have default consntructor
    
    for(int i=0; i<sizeof(vArray)/sizeof(*vArray); i++)
        std::cout << vArray[i].y << std::endl;
    
    Vector3 v3 = *v2;  //calls copy Constructor 
    Vector3 v4 = Vector3(*v2);  //calls Copy Constructor
    Vector3* v5 = new Vector3(*v2); //Copy constructing o the heap
    
    *v5 = v3 = v4 = *v2; //chain assignment possible when return *this
    
    delete v5;
    delete []vArray;   //could be delete [size]vArray
    delete v2;
    delete v1;
    return 0;
}