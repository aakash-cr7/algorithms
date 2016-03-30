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

// Function to sort array using selection sort
void selectionSort(int * a, int len) {
    int min_index;
    for(int i = 0; i < len - 1; i++) {
        // min element in unsorted array
        min_index = i;
        // Loop to find min element
        for(int j = i + 1; j < len; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap(&a[min_index], &a[i]);
        }
    }
}

int main() {
    int a[10] = {9, 3, 1, 4, 6, 8, 2, 7, 5, 10};
    int len = 10;

    selectionSort(a, len);
    printArray(a, len);
   
    return 0;
}
