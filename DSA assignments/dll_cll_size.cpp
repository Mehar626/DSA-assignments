// dll_cll_size.cpp - Find size of DLL and CLL
#include <iostream>
using namespace std;
class Node{public:int data;Node*next;Node*prev;Node(int v){data=v;next=prev=nullptr;}};
class DLL{Node*head;public:DLL(){head=nullptr;}void add(int v){Node*n=new Node(v);if(!head){head=n;return;}Node*t=head;while(t->next)t=t->next;t->next=n;n->prev=t;}int size(){int c=0;Node*t=head;while(t){c++;t=t->next;}return c;}};
class CLL{Node*head;public:CLL(){head=nullptr;}void add(int v){Node*n=new Node(v);if(!head){head=n;head->next=head;return;}Node*t=head;while(t->next!=head)t=t->next;t->next=n;n->next=head;}int size(){if(!head)return 0;int c=0;Node*t=head;do{c++;t=t->next;}while(t!=head);return c;}};
int main(){DLL d;for(int i=1;i<=5;i++)d.add(i);CLL c;for(int i=1;i<=4;i++)c.add(i*10);cout<<"DLL size: "<<d.size()<<"\nCLL size: "<<c.size()<<"\n";}