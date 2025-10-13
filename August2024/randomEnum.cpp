#include <iostream>
#include <random>
#include <ctime>

// Define the unscoped enum
enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    COUNT // Special value to represent the number of enum entries
};

// Function to get a random value from the Color enum
Color getRandomColor() {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr))); // Seed the RNG
    std::uniform_int_distribution<int> dist(0, COUNT - 1); // Generate random index
    return static_cast<Color>(dist(rng)); // Cast to enum type
}

int main() {
    // Generate a random Color value and print it
    Color randomColor = getRandomColor();
    std::cout << "Random Color: " << randomColor << std::endl; // Output will be an integer
    
    // Optionally convert to a readable format
    switch (randomColor) {
        case RED:    std::cout << "Color: RED" << std::endl; break;
        case GREEN:  std::cout << "Color: GREEN" << std::endl; break;
        case BLUE:   std::cout << "Color: BLUE" << std::endl; break;
        case YELLOW: std::cout << "Color: YELLOW" << std::endl; break;
    }

    return 0;
}

