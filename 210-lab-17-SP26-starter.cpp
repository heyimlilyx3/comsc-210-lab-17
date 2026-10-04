#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

void output(Node *);

// Pass by reference so the head pointer itself can be updated when the new
// node becomes the first node in the list.
void addNodeFront(Node *&, float);
void addNodeEnd(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);
void printList(Node *);

int main() {
    Node *head = nullptr;
    int choice = 0;
    int position = 0;
    float value = 0.0;

    // optional: seed random numbers once for menu-based testing
    srand(static_cast<unsigned int>(time(nullptr)));

    do {
        cout << "\n=== Linked List Menu ===\n";
        cout << "1. Add node to front\n";
        cout << "2. Add node to end\n";
        cout << "3. Delete node\n";
        cout << "4. Insert node\n";
        cout << "5. Delete list\n";
        cout << "6. Print list\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 7.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number from 1 to 7.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter a value: ";
                cin >> value;
                addNodeFront(head, value);
                cout << "Node added to the front.\n";
                break;

            case 2:
                cout << "Enter a value: ";
                cin >> value;
                addNodeEnd(head, value);
                cout << "Node added to the end.\n";
                break;

            case 3:
                if (!head) {
                    cout << "The list is empty.\n";
                    break;
                }
                cout << "Enter the position to delete: ";
                cin >> position;
                if (position <= 0) {
                    cout << "Position must be greater than 0.\n";
                    break;
                }
                deleteNode(head, position);
                break;

            case 4:
                if (!head) {
                    cout << "The list is empty. A new node will be inserted as the first node.\n";
                }
                cout << "Enter the position after which to insert: ";
                cin >> position;
                if (position < 0) {
                    cout << "Position must be 0 or greater.\n";
                    break;
                }
                cout << "Enter the value to insert: ";
                cin >> value;
                insertNode(head, position, value);
                break;

            case 5:
                deleteList(head);
                cout << "The list has been deleted.\n";
                break;

            case 6:
                output(head);
                break;

            case 7:
                cout << "bai bai!\n";
                break;
        }

        if (choice == 3 || choice == 4 || choice == 6) {
            cout << "Current list:\n";
            output(head);
        }

    } while (choice != 7);

    deleteList(head);
    return 0;
}

void output(Node *hd) {
    printList(hd);
}

void addNodeFront(Node *&hd, float val) {
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = hd;
    hd = newnode;
}

void addNodeEnd(Node *&hd, float val) {
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = nullptr;

    if (!hd) {
        hd = newnode;
        return;
    }

    Node *current = hd;
    while (current->next) {
        current = current->next;
    }

    current->next = newnode;
}

void deleteNode(Node *&hd, int position) {
    if (!hd || position <= 0) {
        cout << "Unable to delete that node.\n";
        return;
    }

    Node *current = hd;
    Node *prev = nullptr;

    for (int i = 0; i < position - 1 && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "That position does not exist in the list.\n";
        return;
    }

    if (prev == nullptr) {
        hd = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
}

void insertNode(Node *&hd, int position, float val) {
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = nullptr;

    if (!hd) {
        hd = newnode;
        return;
    }

    if (position == 0) {
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
        newnode->next = hd;
        hd = newnode;
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

    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}