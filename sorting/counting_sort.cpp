#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int * a, int len);

void countSort(int *a, int len) {
    int min = a[0];
    int max = a[0];
    // Finding min and max in one pass
    for(int i = 1; i < len; i++) {
        min = (a[i] < min) ? a[i] : min;
        max = (a[i] > max) ? a[i] : max;
    }
    
    // k = range of count and sumcount arrays
    int k = max - min + 1;
    int * count = new int[k]; // count array
    int * sumCount = new int[k]; // array for summing up count
    int * sortedArray = new int[len]; // final sorted array
    
    // Initializing count and sumcount array to 0
    for(int i = 0; i < k; i++) {
        count[i] = 0;
        sumCount[i] = 0;
    }
    // Filling up count array
    for(int i = 0; i < len; i ++) count[a[i] - min]++;

    // Filling up sumCount array using count array
    sumCount[0] = count[0];
    for(int i = 1; i < k; i ++) {
        sumCount[i] = sumCount[i - 1] + count[i];
    }

    //printArray(count, k);
    //printArray(sumCount, k);
    for(int i = 0; i < len; i++) {
        sortedArray[sumCount[a[i] - min] - 1] = a[i];
        sumCount[a[i] - min]--;
    }
    
    cout << "Printing sorted array" << endl;
    printArray(sortedArray, len);
    // Free the dynamically allocated space
    delete [] count;
    delete [] sumCount;
    delete [] sortedArray;
}

// Function to print array
void printArray(int *a, int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main() {
    int a[10] = {5,9,3,9,10,9,2,4,13,10};
    countSort(a, sizeof(a)/sizeof(a[0]));
    return 0;
}
