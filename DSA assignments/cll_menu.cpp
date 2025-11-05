// cll_menu.cpp - Menu-driven Circular Linked List
#include <iostream>
using namespace std;
class Node{public:int data;Node*next;Node(int v){data=v;next=nullptr;}};
class CircularLinkedList{
    Node*head;
public:
    CircularLinkedList(){head=nullptr;}
    void insertEnd(int v){Node*n=new Node(v);if(!head){head=n;head->next=head;return;}Node*t=head;while(t->next!=head)t=t->next;t->next=n;n->next=head;}
    void deleteValue(int v){if(!head){cout<<"Empty\n";return;}Node*t=head,*prev=nullptr;do{if(t->data==v){if(t==head){Node*last=head;while(last->next!=head)last=last->next;head=head->next;last->next=head;}else prev->next=t->next;delete t;cout<<"Deleted "<<v<<"\n";return;}prev=t;t=t->next;}while(t!=head);cout<<"Not found\n";}
    void display(){if(!head){cout<<"Empty\n";return;}Node*t=head;do{cout<<t->data<<(t->next!=head?" -> ":"");t=t->next;}while(t!=head);cout<<" (back to head)\n";}
};
int main(){CircularLinkedList l;int ch,v;do{cout<<"\n1.InsertEnd 2.DeleteVal 3.Display 0.Exit: ";cin>>ch;switch(ch){case 1:cout<<"Val: ";cin>>v;l.insertEnd(v);break;case 2:cout<<"Val: ";cin>>v;l.deleteValue(v);break;case 3:l.display();break;}}while(ch!=0);}