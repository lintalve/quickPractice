#include <print>
#include <random>





int main() {
    
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(-20, 20);
    //std::print("{}\n", gen(dist));
    
    int number = gen(dist);
    
    switch(number) {
        case number >= -20 && number < -10:
            std::print("number is greater|equal -20 and lower than -10 \n");
            break;
        case number >= -10 && number < 0:
            std::print("number is greater|equal -10 and lower than 0 \n");
            break;
        case number == 0:
            std::print("number is 0\n");
            break;
        default:
            std::print("default case\n");
            break;
    }
    
    return 0;
}
