#include <iostream>
using namespace std;


// Fucntion to print array
void printArray(int *a, int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

// Function to sort array using insertion sort
void insertionSort(int *a, int len) {
    int val, j;
    for(int i = 1; i < len; i++) {
        j = i - 1;
        val = a[i];

        /* Move elements from 0....i-1, that are greater than
         * a[i]/val to one position ahead of their current pos
         */
        while(j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = val;
    }
}

int main() {
    int a[10] = {9, 3, 1, 4, 6, 8, 2, 7, 5, 10};
    int len = 10;

    insertionSort(a, len);    
    printArray(a, len);
    return 0;
}
