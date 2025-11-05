// dll_cll_size.cpp
#include <iostream>
using namespace std;
class Node{public:int d;Node*next;Node(int v){d=v;next=NULL;}};
int main(){
    // dll size example: create simple dll
    struct D{int d; D*prev; D*next; D(int v):d(v),prev(NULL),next(NULL){} };
    D* a=new D(1); D* b=new D(2); D* c=new D(3);
    a->next=b; b->prev=a; b->next=c; c->prev=b;
    int sz=0; D* t=a; while(t){ sz++; t=t->next; }
    cout<<"DLL size: "<<sz<<"\n";
    // cll size example
    Node* h=new Node(9); h->next=new Node(11); h->next->next=new Node(34);
    h->next->next->next=new Node(6); h->next->next->next->next=new Node(13);
    Node* tp=h; while(tp->next) tp=tp->next; tp->next=h; // make circular
    int c=0; Node* cur=h; do{ c++; cur=cur->next; } while(cur!=h);
    cout<<"CLL size: "<<c<<"\n";
    return 0;
}