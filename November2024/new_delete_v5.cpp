//in this file we explore deleting some void and built in types
#include <cstdio>
#include <iostream>
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
    Vector3(Vector3&& v) noexcept : x(v.x), y(v.y), z(v.z) {
        //no leave the move from object in empty valid state
        v.x = v.y = v.z = 0.0;
    }
    Vector3& operator=(Vector3&& v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
        //no leave the move from object in empty valid state
        v.x = v.y = v.z = 0.0;  //chain assignment, also possible with u-d objects
        return *this;
    }
    
    ~Vector3() {
        std::cout << "destructing a Vector3" << std::endl;
    }
};

int main(int argc, const char* argv[]) {
    
    int* int1 = new int(345); //pseudo constructor form
    printf("int 1 adress: %p\n", int1);
    float* float1  = new float(24.234f);
    printf("float1 adress: %p\n", float1);
    Vector3* v1 = new Vector3;
    printf("v1 adress: %p\n", v1);
    
    void* voPtr = int1;
    printf("voPtr adress: %p\n", voPtr);
    voPtr = float1;
    printf("voPtr adress: %p\n", voPtr);
    voPtr = v1;
    printf("voPtr adress: %p\n", voPtr);
    
    //This all means that in c and c++ you CAN and
    //should assign any pointer to a void*
    
    
    return 0;
}
