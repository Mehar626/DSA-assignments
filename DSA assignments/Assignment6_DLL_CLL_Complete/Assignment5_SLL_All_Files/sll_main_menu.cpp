// Assignment 5 (Q1–Q4 Combined)
// Singly Linked List using class (Insert, Delete, Search, Reverse, Middle)

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = nullptr; }
};

// Linked List class
class LinkedList {
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Insert at the beginning
    void insertAtStart(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        cout << val << " inserted at start.\n";
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            cout << val << " inserted as first node.\n";
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        cout << val << " inserted at end.\n";
    }

    // Insert after a given value
    void insertAfterValue(int key, int val) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) {
            cout << "Value " << key << " not found.\n";
            return;
        }
        Node* n = new Node(val);
        n->next = t->next;
        t->next = n;
        cout << val << " inserted after " << key << ".\n";
    }

    // Delete from start
    void deleteStart() {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* t = head;
        head = head->next;
        cout << "Deleted " << t->data << " from start.\n";
        delete t;
    }

    // Delete from end
    void deleteEnd() {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        if (!head->next) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* t = head;
        while (t->next->next) t = t->next;
        cout << "Deleted " << t->next->data << " from end.\n";
        delete t->next;
        t->next = nullptr;
    }

    // Delete a specific value
    void deleteValue(int val) {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == val) {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Deleted " << val << " from list.\n";
            return;
        }
        Node* t = head;
        while (t->next && t->next->data != val)
            t = t->next;
        if (!t->next) {
            cout << "Value not found.\n";
            return;
        }
        Node* del = t->next;
        t->next = del->next;
        cout << "Deleted " << val << " from list.\n";
        delete del;
    }

    // Search for an element
    void search(int val) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == val) {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << val << " not found in the list.\n";
    }

    // Find middle element
    void findMiddle() {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed.\n";
    }

    // Display all elements
    void display() {
        if (!head) {
            cout << "List empty.\n";
            return;
        }
        Node* t = head;
        cout << "List: ";
        while (t) {
            cout << t->data;
            if (t->next) cout << " -> ";
            t = t->next;
        }
        cout << "\n";
    }
};

// Main menu
int main() {
    LinkedList list;
    int ch, val, key;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert After Value\n";
        cout << "4. Delete Start\n5. Delete End\n6. Delete by Value\n";
        cout << "7. Search Element\n8. Find Middle\n9. Reverse List\n10. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtStart(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Insert after value: "; cin >> key; cout << "New value: "; cin >> val; list.insertAfterValue(key, val); break;
            case 4: list.deleteStart(); break;
            case 5: list.deleteEnd(); break;
            case 6: cout << "Enter value to delete: "; cin >> val; list.deleteValue(val); break;
            case 7: cout << "Enter value to search: "; cin >> val; list.search(val); break;
            case 8: list.findMiddle(); break;
            case 9: list.reverse(); break;
            case 10: list.display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (ch != 0);
    return 0;
}
