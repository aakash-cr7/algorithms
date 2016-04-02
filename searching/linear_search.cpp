#include <iostream>
using namespace std;

bool linearSearch(int *a, int length, int item_to_find) {
    for(int i = 0; i < length; i++) {
        if(a[i] == item_to_find) {
            return true;
        }
    }
    return false;
}

int linearSearchPos(int *a, int length, int item_to_find)) {
    for(int i = 0; i < length; i++) {
        if(a[i] == item_to_find) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[7] = {1, 4, 5, 9, 1, 0};
    int length = 7;
    int item_to_find = 11;
    cout << linearSearch(a, length, item_to_find) << endl;
}
