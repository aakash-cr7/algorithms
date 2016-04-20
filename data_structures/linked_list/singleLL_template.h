#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

// class definition for writing friend function ostream in class Node
template <typename T>
class SingleLinkedList;

template <typename U>
class Node {
    U data;
    Node * next;

    public:
    Node() : next(0), data(0) {}
    Node(const U & d) : next(0), data(d) {}
    // copy constructor
    Node(const Node & n) : next(0), data(n.data) {} 

    template <typename V>
    friend class SingleLinkedList;
    template <typename W>
    friend ostream & operator<<(ostream & out, const SingleLinkedList<W> &);
};

template <typename T>
class SingleLinkedList {
    Node<T> * head;

    void copyas(const SingleLinkedList & L) {
        const Node<T> * it = L.head;
        Node<T> * tail = 0;
        while(it) {
            Node<T> * newNode = new Node<T>(*it);
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
            Node<T> * temp = head;
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
        Node<T> * newNode = new Node<T>(d);
        newNode->next = head;
        head = newNode;
        return;
    }
    void printList() {
        Node<T> * it = head;
        while(it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL" << endl;
        return;
    }
    void deleteFromHead() {
        if (head == NULL) return;
        Node<T> * temp = head;
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
            Node<T> * it = head;
            while(it->next) {
                it = it->next;
            }
            it->next = temp.head;
        }
        temp.head = 0;
        return *this;
    }
    SingleLinkedList & operator+=(const T & el) {
        insertAtTheEnd(el);
        return *this;
    }
    SingleLinkedList operator+(const T & el) {
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
        Node<T> * it = ans.head;
        while(it->next) {
            it = it->next;
        }
        it->next = ansright.head;
        ansright.head = 0;
        return ans;
    }
    void insertAtTheEnd(const T &);
    template <typename V>
    friend ostream & operator<<(ostream &, const SingleLinkedList<V> &);
};

template <typename T>
void SingleLinkedList<T>::insertAtTheEnd(const T & d) {
    Node<T> * newNode = new Node<T>(d);

    if(!head) {
        head = newNode;
        return;
    }
    Node<T> * it = head;
    while(it->next) {
        it = it->next;
    }
    it->next = newNode;
    return;
}

template <typename V>
ostream & operator<<(ostream & out, const SingleLinkedList<V> & L) {
    const Node<V> * it = L.head;
    while(it) {
        out << it->data << "-->";
        it = it->next;
    }
    out << "NULL";
    return out;
}
#endif
