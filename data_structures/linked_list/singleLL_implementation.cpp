#include <iostream>
using namespace std;

class Node {
    int data;
    Node * next;

    public:
    Node() : next(0), data(0) {}
    Node(int d) : next(0), data(d) {}
    // copy constructor
    Node(const Node & n) : next(0), data(n.data) {} 

    friend class SingleLinkedList;
};

class SingleLinkedList {
    Node * head;

    void copyas(const SingleLinkedList & L) {
    }
    
    public:
    SingleLinkedList(): head(0) {}

    // copy constructor
    SingleLinkedList(const SingleLinkedList & L) : head(0) {
        copyas(L);
    }
    void clear() {
        while(head) {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }
    ~SingleLinkedList() {
        clear();
        // or (*this).clear()
        // or this->clear()
    }
    void insertAtHead(int d) {
        Node * newNode = new Node(d);
        newNode->next = head;
        head = newNode;
        return;
    }
    void printList() {
        Node * it = head;
        while(it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL" << endl;
        return;
    }
    void deleteFromHead() {
        if (head == NULL) return;
        Node * temp = head;
        head = head->next;
        delete temp;
        return;
    }
    void insertAtTheEnd(int);
};

void SingleLinkedList::insertAtTheEnd(int d) {
    Node * newNode = new Node(d);

    if(!head) {
        head = newNode;
        return;
    }
    Node * it = head;
    while(it->next) {
        it = it->next;
    }
    it->next = newNode;
    return;
}

int main() {
    SingleLinkedList L1;
    for(int i = 1; i < 6; i++) {
        L1.insertAtHead(i);
    }
    L1.deleteFromHead();
    L1.insertAtTheEnd(100);
    L1.printList();
    return 0;
}

























