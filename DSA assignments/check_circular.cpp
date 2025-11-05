// check_circular.cpp - Check if linked list is circular
#include <iostream>
using namespace std;
class Node{public:int data;Node*next;Node(int v){data=v;next=nullptr;}};
class LinkedList{Node*head;public:LinkedList(){head=nullptr;}void add(int v){Node*n=new Node(v);if(!head){head=n;return;}Node*t=head;while(t->next)t=t->next;t->next=n;}void makeCircular(){if(!head)return;Node*t=head;while(t->next)t=t->next;t->next=head;}bool isCircular(){if(!head)return false;Node*t=head->next;while(t&&t!=head)t=t->next;return(t==head);} };
int main(){LinkedList l;for(int i=1;i<=5;i++)l.add(i);cout<<(l.isCircular()?"Circular\n":"Not Circular\n");l.makeCircular();cout<<(l.isCircular()?"Circular\n":"Not Circular\n");}