// check_circular.cpp
#include <iostream>
using namespace std;
class Node{public:int d;Node*next;Node(int v){d=v;next=NULL;}};
bool isCircular(Node* head){
    if(!head) return false;
    Node* t=head->next;
    while(t && t!=head) t=t->next;
    return t==head;
}
int main(){
    Node* h=new Node(2); h->next=new Node(4); h->next->next=new Node(6); h->next->next->next=new Node(7);
    h->next->next->next->next=new Node(5);
    // make circular for test
    Node* t=h; while(t->next) t=t->next; t->next=h;
    cout << (isCircular(h)? "True":"False") << "\n";
    return 0;
}