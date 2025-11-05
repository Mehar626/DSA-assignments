// dll_menu.cpp - Menu-driven Doubly Linked List
#include <iostream>
using namespace std;
class Node{public:int data;Node*prev;Node*next;Node(int v){data=v;prev=next=nullptr;}};
class DoublyLinkedList{
    Node*head;
public:
    DoublyLinkedList(){head=nullptr;}
    void insertStart(int v){Node*n=new Node(v);if(!head){head=n;return;}n->next=head;head->prev=n;head=n;}
    void insertEnd(int v){Node*n=new Node(v);if(!head){head=n;return;}Node*t=head;while(t->next)t=t->next;t->next=n;n->prev=t;}
    void deleteStart(){if(!head){cout<<"Empty\n";return;}Node*t=head;head=head->next;if(head)head->prev=nullptr;delete t;}
    void deleteEnd(){if(!head){cout<<"Empty\n";return;}if(!head->next){delete head;head=nullptr;return;}Node*t=head;while(t->next)t=t->next;t->prev->next=nullptr;delete t;}
    void deleteValue(int v){if(!head){cout<<"Empty\n";return;}Node*t=head;while(t&&t->data!=v)t=t->next;if(!t){cout<<"Not found\n";return;}if(t==head)head=head->next;if(t->prev)t->prev->next=t->next;if(t->next)t->next->prev=t->prev;delete t;}
    void displayForward(){Node*t=head;if(!t){cout<<"Empty\n";return;}while(t){cout<<t->data<<(t->next?" <-> ":"\n");t=t->next;}}
    void displayBackward(){if(!head){cout<<"Empty\n";return;}Node*t=head;while(t->next)t=t->next;while(t){cout<<t->data<<(t->prev?" <-> ":"\n");t=t->prev;}}
};
int main(){DoublyLinkedList l;int ch,v;do{cout<<"\n1.InsertStart 2.InsertEnd 3.DeleteStart 4.DeleteEnd 5.DeleteVal 6.DisplayFwd 7.DisplayBack 0.Exit: ";cin>>ch;switch(ch){case 1:cout<<"Val: ";cin>>v;l.insertStart(v);break;case 2:cout<<"Val: ";cin>>v;l.insertEnd(v);break;case 3:l.deleteStart();break;case 4:l.deleteEnd();break;case 5:cout<<"Val: ";cin>>v;l.deleteValue(v);break;case 6:l.displayForward();break;case 7:l.displayBackward();break;}}while(ch!=0);}