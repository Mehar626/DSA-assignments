// dll_cll_menu.cpp
// Menu-driven program for basic operations on Doubly and Circular Linked List
#include <iostream>
using namespace std;

class DNode {
public:
    int data; DNode* prev; DNode* next;
    DNode(int v){ data=v; prev=NULL; next=NULL; }
};

class DoublyList {
    DNode* head;
public:
    DoublyList(){ head=NULL; }
    void insertAtStart(int v){
        DNode* n=new DNode(v);
        if(!head){ head=n; return; }
        n->next = head; head->prev=n; head=n;
    }
    void insertAtEnd(int v){
        DNode* n=new DNode(v);
        if(!head){ head=n; return; }
        DNode* t=head; while(t->next) t=t->next; t->next=n; n->prev=t;
    }
    void display(){
        if(!head){ cout<<"Empty\n"; return; }
        DNode* t=head; while(t){ cout<<t->data; if(t->next) cout<<" -> "; t=t->next; } cout<<"\n";
    }
    int size(){
        int c=0; DNode* t=head; while(t){ c++; t=t->next; } return c;
    }
    bool isPalindrome(){
        if(!head) return true;
        DNode* l=head; DNode* r=head;
        while(r->next) r=r->next;
        while(l!=r && l->prev!=r){
            if(l->data!=r->data) return false;
            l=l->next; r=r->prev;
        }
        return true;
    }
};

// Circular singly linked list simple implementation
class CNode { public: int data; CNode* next; CNode(int v){data=v; next=NULL;} };
class CircularList {
    CNode* head;
public:
    CircularList(){ head=NULL; }
    void insertEnd(int v){
        CNode* n=new CNode(v);
        if(!head){ head=n; head->next=head; return; }
        CNode* t=head; while(t->next!=head) t=t->next; t->next=n; n->next=head;
    }
    void displayRepeat(){
        if(!head){ cout<<"Empty\n"; return; }
        CNode* t=head;
        do{ cout<<t->data; if(t->next!=head) cout<<" "; t=t->next; } while(t!=head);
        cout<<" " << head->data << "\n";
    }
    int size(){
        if(!head) return 0; int c=0; CNode* t=head; do{ c++; t=t->next; } while(t!=head); return c;
    }
    bool isCircular(){
        if(!head) return false;
        CNode* t=head->next;
        while(t && t!=head) t=t->next;
        return t==head;
    }
};

int main(){
    DoublyList dl; for(int i=1;i<=5;i++) dl.insertAtEnd(i);
    cout<<"Doubly List: "; dl.display();
    cout<<"Size: "<<dl.size()<<"\n";
    cout<<"Palindrome? "<<(dl.isPalindrome()? "Yes":"No")<<"\n";

    CircularList cl; int a[]={20,100,40,80,60}; for(int x:a) cl.insertEnd(x);
    cout<<"Circular display repeat: "; cl.displayRepeat();
    cout<<"CL size: "<<cl.size()<<"\n";
    cout<<"Is Circular? "<<(cl.isCircular()? "Yes":"No")<<"\n";
    return 0;
}