#include <cstdlib>
#include <cstdio>
#include <random>

class string {
    static const int increment = 20;
    int capacity {};
    int index {};
    char array[20];
    char* storage {nullptr};
    void increase(int amount);
public:
    string() {}
    string(const char* s) {
        const char* ptr = s;
        int count {};
        char c;
        while((c = *ptr) != '\0') {
            count++;
            ptr++;
        }
        ptr = s;
        c = 0;
        increase(increment);
        while(*ptr != '\0') {
            if(count > 19)
            { *storage = *ptr; } else { *array = *ptr;}
            ptr++;
        }
            
    }
    string(const string& s) : capacity(s.capacity), index(s.index) {
        storage = (char*)malloc(s.capacity);
        for(int i=0; i<s.capacity; i++) {
            storage[i] = s.storage[i];
        }
    }
    ~string() {free(storage); }
};

class integer {
    int theInt {};
public:
    integer(const int& i) : theInt(i) {
    }
    integer& operator=(const int& i) {
        theInt = i;
        return *this;
    }
    int get() const { return theInt; }
};

int main(int argc, const char* argv[]) {
    std::mt19937 gnr(std::random_device{}());
    std::uniform_int_distribution<int> dist(-10, 10);
    integer in = 345;   //copy constructor
    
    printf("%i\n", in.get());
    printf("%i\n", dist(gnr));
    return 0;
}