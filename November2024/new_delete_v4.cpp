#include <iostream>
#include <format>



static const int size{32};

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

class NewTest {
    int someInt{};
    float someFloat{};
public:
    NewTest() : someInt(34), someFloat(56.3342) {
        std::cout << "creating NewTest" << std::endl;
    }
    ~NewTest() {std::cout << "destroing NewTest" << std::endl; }
    
    void* operator new(size_t sz) {
        puts("custom new operator for a single NewTest object\n");
        void* m = malloc(sz);
        if(m) return m;
        puts("no memory for you\n");
        exit(1);
    }
    void* operator new[](size_t sz) {
        puts("custom new[] operator of NewTest objs\n");
        void* m = malloc(sz);
        if(m) return m;
        puts("no memory for you\n");
        exit(1);
    }
    void operator delete(void* ptr) {
        printf("custom delete operator for a single NewTest object\n");
        free(ptr);
    }
    void operator delete[](void* ptr) {
        printf("custom delete[] operator for aa array of NewTest objects\n");
        free(ptr);
    }
};

int main(int argc, const char* argv[]) {
    std::cout << "things" << std::endl;
    
    Vector3* v1 = new Vector3(2.5, 3.5, 4.5);
    Vector3* v2 = new Vector3(2.2, 3.3, 4.4);
    std::cout << "v1 is: " << "(" << v1->x << ", " << v1->y << ", " << v1->z << ")\n";
    *v1 = std::move(*v2);
    std::cout << "v1 is: " << "(" << v1->x << ", " << v1->y << ", " << v1->z << ")\n";
    std::cout << "v2 is: " << "(" << v2->x << ", " << v2->y << ", " << v2->z << ")\n";
    
    NewTest* nt0 = new NewTest;
    delete nt0;
    
    NewTest* nt1 = new NewTest[size]; //there is a default constructor
    delete []nt1;
    
    return 0;
}
