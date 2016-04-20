#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

// class definition for writing friend function ostream in class Node
class SingleLinkedList;

class Node {
    int data;
    Node * next;

    public:
    Node() : next(0), data(0) {}
    Node(int d) : next(0), data(d) {}
    // copy constructor
    Node(const Node & n) : next(0), data(n.data) {} 

    friend class SingleLinkedList;
    friend ostream & operator<<(ostream & out, const SingleLinkedList &);
};

class SingleLinkedList {
    Node * head;

    void copyas(const SingleLinkedList & L) {
        const Node * it = L.head;
        Node * tail = 0;
        while(it) {
            Node * newNode = new Node(*it);
            if(!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            it = it->next;
        }
        return;
    }
    
    public:
    SingleLinkedList(): head(0) {}

    // copy constructor
    SingleLinkedList(const SingleLinkedList & L) : head(0) {
        // deep copy
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
    // copy assignment operator
    SingleLinkedList & operator=(const SingleLinkedList & L) {
        clear();
        copyas(L);
        return *this;
    }
    SingleLinkedList & operator+=(const SingleLinkedList & L) {
        SingleLinkedList temp(L);
        if(!head) {
            head = temp.head;
        } else {
            Node * it = head;
            while(it->next) {
                it = it->next;
            }
            it->next = temp.head;
        }
        temp.head = 0;
        return *this;
    }
    SingleLinkedList & operator+=(int el) {
        insertAtTheEnd(el);
        return *this;
    }
    SingleLinkedList operator+(int el) {
        SingleLinkedList temp = *this;
        temp.insertAtTheEnd(el);
        return temp;
    }
    SingleLinkedList operator+(const SingleLinkedList & L) {
        SingleLinkedList ans = *this;
        SingleLinkedList ansright = L;
        if(!ans.head) {
            return ansright;
        }
        Node * it = ans.head;
        while(it->next) {
            it = it->next;
        }
        it->next = ansright.head;
        ansright.head = 0;
        return ans;
    }
    void insertAtTheEnd(int);
    friend ostream & operator<<(ostream &, const SingleLinkedList &);
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

ostream & operator<<(ostream & out, const SingleLinkedList & L) {
    const Node * it = L.head;
    while(it) {
        out << it->data << "-->";
        it = it->next;
    }
    out << "NULL";
    return out;
}
#endif
