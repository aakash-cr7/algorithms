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
    friend void radixSort(SingleLinkedList &);
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
    void insertAtTheEnd(Node * n) {
        n->next = 0;
        if(!head) {
            head = n;
            return;
        }
        Node * it = head;
        while(it->next) {
            it = it->next;
        }
        it->next = n;
        return;
    }
    void insertAtTheEnd(int);
    friend ostream & operator<<(ostream &, const SingleLinkedList &);
    friend void radixSort(SingleLinkedList &);

    /* Helper functions for Radix sort **/

    // Function to REMOVE(not delete) the element from head and return that element
    Node * softDeleteFromHead() {
        if(!head) return 0;
        Node * temp = head;
        head = head->next;
        return temp;
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == NULL;
    }
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

void radixSort(SingleLinkedList & L) {
    if(!L.head || !L.head->next) return;
    int min = L.head->data;
    int max = L.head->data;
    Node * it = L.head;
    while(it) {
        if(it->data < min) {
            min = it->data;
        } 
        if(it->data > max) {
            max = it->data;
        }
        it = it->next;
    }
    // if a -ve number is present, subtract the least -ve number from all number than sort them
    if(min < 0) {
        it = L.head;
        while(it) {
            it->data -= min;
            it = it->next;
        }
        max -= min;
    }
    // variable to store how many passes we have to make
    int totalrounds = 0;
    while(max > 0) {
        totalrounds++;
        max = max/10;
    }
    SingleLinkedList buckets[10];
    int k = 1;
    for(int i = 0; i < totalrounds; i++) {
        while(!L.isEmpty()) {
            Node * temp = L.softDeleteFromHead();
            buckets[(temp->data/k) % 10].insertAtTheEnd(temp);
        }
        for(int j = 0; j < 10; j++) {
            while(!buckets[j].isEmpty()) {
                Node * temp = buckets[j].softDeleteFromHead();
                L.insertAtTheEnd(temp);
            }
        }
        k *= 10;
    }
    // now if min is less than 0, add min to every element to get original numbers
    if(min < 0) {
        Node * it = L.head;
        while(it) {
            it->data += min;
            it = it->next;
        }
    }
}

int main() {
    SingleLinkedList L1;
    int n;
    for(int i = 0; i < 11; i++) {
        cin >> n;
        L1.insertAtTheEnd(n);
    }
    cout << "The list is" << endl;
    L1.printList();
    radixSort(L1);

    cout << "After sorting" << endl;
    L1.printList();
    return 0;
}
