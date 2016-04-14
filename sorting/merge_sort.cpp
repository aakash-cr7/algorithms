#include <iostream>

using namespace std;

// Function to merge array L and R to A(sorted)
void merge(int * A, int * L, int * R, int leftSize, int rightSize) {
    int i = 0; // index of Left sub array L
    int j = 0; // index of Right sub array R
    int k = 0; // index of array A

    while(i < leftSize && j < rightSize) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // If one of the array is finished, shift all the elements of ther array to A
    while(i < leftSize) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < rightSize) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort array
void mergeSort(int * A, int size) {
    int mid = size / 2;

    // if array has 1 element return
    if(size < 2) return;

    // creating legt L and right R sub arrays
    int * L = new int(mid);
    int * R = new int(size - mid);

    // copy elements from A to L
    for(int i = 0; i < mid; i++) 
        L[i] = A[i];
    // copy elements from A to R
    for(int j = mid; j < size; j++)
        R[j - mid] = A[j];

    mergeSort(L, mid); // sort left sub array
    mergeSort(R, size - mid); // sort right sub array
    merge(A, L, R, mid, size - mid); // merging L and R into A(sorted)

    delete [] L;
    delete [] R;
}

void printArray(int * A, int size) {
    for(int i = 0; i < size; i++) 
        cout << A[i] << ", ";
    cout << endl;
}

int main() {
    int A[] = {2, 4, 1, 6, 8, 5, 3, 7};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    //cout << size;
    mergeSort(A, size);
    cout << "Sorted array" << endl;
    printArray(A, size);
    return 0;
}
