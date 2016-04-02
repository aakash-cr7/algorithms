#include <iostream>
using namespace std;

bool binarySearchIterative(int *a, int length, int item_to_find) {
    int leftPos = 0; 
    int rightPos = length - 1;
    int mid;

    while(leftPos <= rightPos) {
        mid = (leftPos + rightPos) / 2; // finding middle index
        if(a[mid] == item_to_find) {
            return true;
        }
        else if(item_to_find < a[mid]) {
            rightPos = mid - 1;
        } else {
            leftPos = mid + 1;
        }
    }
    return false;
}

int main() {
    int a[7] = {1, 4, 5, 9, 14, 30};
    int length = 7;
    int item_to_find = 9;
    cout << binarySearchIterative(a, length, item_to_find) << endl;
}
