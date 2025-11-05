// cll_display_repeat.cpp
#include <iostream>
using namespace std;
class Node{public:int d;Node*next;Node(int v){d=v;next=NULL;}};
int main(){
    Node *h=new Node(20); h->next=new Node(100); h->next->next=new Node(40);
    h->next->next->next=new Node(80); h->next->next->next->next=new Node(60);
    // make circular
    Node* t=h; while(t->next) t=t->next; t->next=h;
    // display repeating head at end
    Node* cur=h; do{ cout<<cur->d; if(cur->next!=h) cout<<" "; cur=cur->next; } while(cur!=h);
    cout<<" "<<h->d<<"\n";
    return 0;
}