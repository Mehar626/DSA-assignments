// dll_palindrome.cpp
#include <iostream>
using namespace std;
class Node{public:char c;Node*prev;Node*next;Node(char ch){c=ch;prev=next=NULL;}};
int main(){
    // build dll of characters: r a d a r
    Node *n1=new Node('r'), *n2=new Node('a'), *n3=new Node('d'), *n4=new Node('a'), *n5=new Node('r');
    n1->next=n2; n2->prev=n1; n2->next=n3; n3->prev=n2; n3->next=n4; n4->prev=n3; n4->next=n5; n5->prev=n4;
    Node *l=n1, *r=n1; while(r->next) r=r->next;
    bool pal=true;
    while(l!=r && l->prev!=r){
        if(l->c != r->c){ pal=false; break; }
        l=l->next; r=r->prev;
    }
    cout<<(pal? "True":"False")<<"\n";
    return 0;
}