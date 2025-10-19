#include <print>
#include <random>


int main() {
    
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 4);
    //std::print("{}\n", gen(dist));
    
    int number = dist(gen);
    
    switch(number) {
        case 0:
            std::print("number is Zero\n");
            break;
        case 1:
            std::print("number is One\n");
            break;
        case 2:
            std::print("number is Two\n");
            break;
        case 3:
            std::print("number is Three\n");
            break;
        case 4:
            std::print("number is Four\n");
            break;
        default:
            std::print("default case\n");
            break;
    }
    
    return 0;
}

