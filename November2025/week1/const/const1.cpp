#include <iostream>
#include <random>


class MyType {
public:
    int integer {};
    MyType() : integer(234) {}
    MyType(int i) : integer(i) {}
};

int main(int argc, const char* argv[]) {


    std::vector<MyType> array;
    for(int i=0; i<10; i++) {
        array.push_back(i);
    }
    const std::vector<MyType> constVector = array;

    for(int j=0; j<10; j++) {
        std::cout << array[j].integer << " ";   //calls const T& operator[] const;
    }
    puts("\n");

    







    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(-10, 10);

    for(int i=0; i<6; i++) std::cout << dist(rng) << " ";
    puts("\n");
    return 0;
    
}