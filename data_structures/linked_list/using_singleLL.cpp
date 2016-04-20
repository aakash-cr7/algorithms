#include <iostream>
#include "singleLL_implementation.h"

using namespace std;

int main() {
    SingleLinkedList L1;

    // Testing methods of LL class
    cout << "Testing methods of LL class" << endl;
    for(int i = 1; i < 6; i++) {
        L1.insertAtHead(i);
    }
    L1.deleteFromHead();
    L1.insertAtTheEnd(100);
    L1.printList();

    // Testing copy assignment operator
    cout << "Testing copy assignment operator" << endl;
    SingleLinkedList L2;
    L2 = L1;
    L2.printList();

    // Testing += operator
    cout << "Testing += operator" << endl;
    L1 += L2;
    L1 += 10000;
    L1.printList();

    // Testing << operator
    cout << "Testing << operator" << endl;
    cout << L1 << endl;

    // Testing + operator
    cout << "Testing + operator" << endl;
    cout << L1 + L2 << endl;
    cout << L1 + 70000000 << endl;
    cout << L1 << endl;
    return 0;
}

