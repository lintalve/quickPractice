#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "cube.obj"; // Replace with the actual file name if different

    ifstream file(filename); // Open the .obj file for reading
    if (!file.is_open()) {   // Check if the file was successfully opened
        cerr << "Error: Could not open the file " << filename << "!" << endl;
        return 1;
    }

    string line; // To store each line from the file
    while (getline(file, line)) { // Read line by line
        cout << line << endl;     // Print each line immediately
    }

    file.close(); // Close the file when done
    return 0;
}

