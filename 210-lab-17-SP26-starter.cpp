#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

void addNodeFront(Node *&, float);

void addNodeEnd(Node *&, float);

void deleteNode(Node *&, int);

void insertNode(Node *&, int, float);

void deleteList(Node *&);

void printList(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addNodeFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addNodeFront(Node *&hd, float val) {
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = hd;
    hd = newnode;
}

void deleteNode(Node *&hd, int position) {
    if (!hd) return; // List is empty

    Node *current = hd;
    Node *prev = nullptr;

    for (int i = 0; i < position - 1 && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) return; // Position is out of bounds

    if (prev == nullptr) {
        // Deleting the head node
        hd = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
}

void insertNode(Node *&hd, int position, float val) {
    Node *newnode = new Node;
    newnode->value = val;

    if (!hd || position <= 0) {
        newnode->next = hd;
        hd = newnode;
        return;
    }

    Node *current = hd;
    Node *prev = nullptr;

    for (int i = 0; i < position && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!prev) {
        delete newnode;
        return;
    }

    prev->next = newnode;
    newnode->next = current;
}

void deleteList(Node *&hd) {
    Node *current = hd;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    hd = nullptr;
}

void printList(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    Node *current = hd;
    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "nullptr\n";
}