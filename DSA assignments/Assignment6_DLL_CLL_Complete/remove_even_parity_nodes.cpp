// remove_even_parity_nodes.cpp
// Remove nodes whose binary parity (count of 1s) is even
#include <iostream>
using namespace std;
int parity(int x){ int c=0; while(x){ c+=x&1; x>>=1; } return c%2; }
struct Node{ int val; Node* next; Node(int v):val(v),next(NULL){} };
Node* removeParity(Node* head){
    while(head && parity(head->val)==0){ Node* t=head; head=head->next; delete t; }
    Node* cur=head;
    while(cur && cur->next){
        if(parity(cur->next->val)==0){ Node* t=cur->next; cur->next=t->next; delete t; }
        else cur=cur->next;
    }
    return head;
}
int main(){
    Node* h=new Node(9); h->next=new Node(11); h->next->next=new Node(34); h->next->next->next=new Node(6); h->next->next->next->next=new Node(13); h->next->next->next->next->next=new Node(21);
    h=removeParity(h);
    Node* t=h; while(t){ cout<<t->val<<(t->next? " ":""); t=t->next; } cout<<"\n";
    return 0;
}