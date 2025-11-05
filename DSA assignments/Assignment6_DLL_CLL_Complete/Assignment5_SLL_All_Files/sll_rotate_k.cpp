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

    void rotateByK(int k){
        if(!head || k == 0) return;

        // Find length and tail
        Node* t = head;
        int len = 1;
        while(t->next){ t = t->next; len++; }
        t->next = head;     // make circular

        k = k % len;
        int steps = len - k;
        while(steps--) t = t->next;

        head = t->next;
        t->next = nullptr;
    }

    void display(){
        Node* t = head;
        while(t){ cout << t->data << (t->next?" -> ":"\n"); t = t->next; }
    }
};

int main(){
    LinkedList list;
    for(int i=1;i<=8;i++) list.insertEnd(i);
    cout<<"Original: "; list.display();
    list.rotateByK(3);
    cout<<"Rotated by 3: "; list.display();
    return 0;
}
