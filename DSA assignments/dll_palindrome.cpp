// dll_palindrome.cpp - Check if DLL is palindrome
#include <iostream>
using namespace std;
class Node{public:int data;Node*next;Node*prev;Node(int v){data=v;next=prev=nullptr;}};
class DLL{Node*head;public:DLL(){head=nullptr;}void add(int v){Node*n=new Node(v);if(!head){head=n;return;}Node*t=head;while(t->next)t=t->next;t->next=n;n->prev=t;}bool isPalindrome(){if(!head)return true;Node*s=head,*e=head;while(e->next)e=e->next;while(s!=e&&e->next!=s){if(s->data!=e->data)return false;s=s->next;e=e->prev;}return true;}void show(){Node*t=head;while(t){cout<<t->data<<" ";t=t->next;}cout<<"\n";}};
int main(){DLL d;d.add(1);d.add(2);d.add(3);d.add(2);d.add(1);d.show();cout<<(d.isPalindrome()?"Palindrome\n":"Not Palindrome\n");}