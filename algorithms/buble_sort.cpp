#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, so we don't need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int myArray[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    bubbleSort(myArray, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << myArray[i] << " ";
    }

    return 0;
}
