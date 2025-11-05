// queue_interleave.cpp
// Interleave first half and second half of queue
#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q){
    int n = q.size();
    if (n%2!=0) { cout<<"Requires even number of elements\n"; return; }
    int half = n/2;
    queue<int> first;
    for(int i=0;i<half;i++){ first.push(q.front()); q.pop(); }
    // interleave by alternating
    while(!first.empty()){
        q.push(first.front()); first.pop();
        q.push(q.front()); q.pop();
    }
}

int main(){
    queue<int> q;
    int a[]={4,7,11,20,5,9};
    for(int x: a) q.push(x);
    interleave(q);
    while(!q.empty()){ cout<<q.front()<<(q.size()? " ":""); q.pop(); }
    cout<<"\n";
    return 0;
}