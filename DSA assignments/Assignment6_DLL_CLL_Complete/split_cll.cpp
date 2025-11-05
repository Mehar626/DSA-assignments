// split_cll.cpp
// Split circular linked list into two halves
#include <iostream>
using namespace std;
class Node{public:int data;Node*next;Node(int v){data=v;next=NULL;}};
int main(){
    Node* head=new Node(10); head->next=new Node(4); head->next->next=new Node(9);
    // make circular
    Node* t=head; while(t->next) t=t->next; t->next=head;
    // use slow-fast to split
    Node *slow=head, *fast=head;
    while(fast->next!=head && fast->next->next!=head){ slow=slow->next; fast=fast->next->next; }
    Node* head1=head;
    Node* head2=slow->next;
    slow->next=head1;
    if(fast->next==head) fast->next=head2; else fast->next=head2;
    // print head1
    Node* p=head1; do{ cout<<p->data<<" "; p=p->next; } while(p!=head1); cout<<"\n";
    // print head2
    p=head2; do{ cout<<p->data<<" "; p=p->next; } while(p!=head2); cout<<"\n";
    return 0;
}