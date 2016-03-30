#include <iostream>
using namespace std;

// Function to swap 2 elements
void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// Fucntion to print array
void printArray(int *a, int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// Function to sort array using bubble sort 
void bubbleSort(int *a, int len) {
    for(int i = 0; i < len - 1; i++) {

        // Last i elements will already be sorted
        for(int j = 0; j < len - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main() {
    int a[10] = {5, 3, 1, 4, 6, 8, 2, 9, 7, 10};
    int len = 10;

    bubbleSort(a, len);
    printArray(a, len);
    return 0;
}
