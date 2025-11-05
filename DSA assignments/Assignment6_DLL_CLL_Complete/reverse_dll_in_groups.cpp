// reverse_dll_in_groups.cpp
// Reverse doubly linked list in groups of k
#include <iostream>
using namespace std;
class Node{ public: int val; Node* prev; Node* next; Node(int v){val=v; prev=next=NULL;} };
Node* reverseGroups(Node* head, int k){
    Node* curr=head; Node* newHead=NULL; int count=0;
    while(curr && count<k){ Node* nxt=curr->next; curr->next=curr->prev; curr->prev=nxt; newHead=curr; curr=nxt; count++; }
    if(curr){ head->next = reverseGroups(curr, k); if(head->next) head->next->prev = head; }
    return newHead;
}
int main(){
    Node* a=new Node(1); a->next=new Node(2); a->next->prev=a; a->next->next=new Node(3); a->next->next->prev=a->next; a->next->next->next=new Node(4); a->next->next->next->prev=a->next->next; a->next->next->next->next=new Node(5); a->next->next->next->next->prev=a->next->next->next; a->next->next->next->next->next=new Node(6); a->next->next->next->next->next->prev=a->next->next->next->next;
    Node* res = reverseGroups(a, 2);
    Node* t=res; while(t){ cout<<t->val<<(t->next? " ":""); t=t->next; } cout<<"\n";
    return 0;
}