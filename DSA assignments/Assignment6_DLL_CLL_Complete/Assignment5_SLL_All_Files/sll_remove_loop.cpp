#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v){ data = v; next = nullptr; }
};

class LinkedList {
    Node* head;
public:
    LinkedList(){ head = nullptr; }

    void insertEnd(int v){
        Node* n = new Node(v);
        if(!head){ head = n; return; }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
    }

    void createLoop(int pos){
        if(pos <= 0) return;
        Node* loopNode = nullptr;
        Node* t = head;
        int count = 1;
        while(t->next){
            if(count == pos) loopNode = t;
            t = t->next; count++;
        }
        t->next = loopNode;
    }

    bool detectAndRemoveLoop(){
        Node* slow = head;
        Node* fast = head;
        bool loopFound = false;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ loopFound = true; break; }
        }

        if(!loopFound) return false;

        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
        return true;
    }

    void display(){
        Node* t = head; int count=0;
        while(t && count<50){  // limit for safety
            cout << t->data << " ";
            t = t->next; count++;
        }
        cout << "\n";
    }
};

int main(){
    LinkedList list;
    for(int i=1;i<=6;i++) list.insertEnd(i);
    list.createLoop(3);    // create a loop at node 3
    if(list.detectAndRemoveLoop()) cout<<"Loop detected and removed\n";
    else cout<<"No loop found\n";
    list.display();
    return 0;
}
