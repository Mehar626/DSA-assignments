// queue_sort_check_stack.cpp
// Check if queue can be sorted into increasing order using a stack and another queue
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canBeSorted(queue<int> q){
    stack<int> s;
    queue<int> out;
    int expected = 1; // if queue has 1..n in some order
    int n = q.size();
    // We will simulate: allowed ops - pop from q, push/pop to stack, enqueue to out.
    for(int i=0;i<n;i++){
        int x = q.front(); q.pop();
        while(!s.empty() && s.top()==expected){ out.push(s.top()); s.pop(); expected++; }
        if(x==expected){ out.push(x); expected++; }
        else s.push(x);
    }
    while(!s.empty() && s.top()==expected){ out.push(s.top()); s.pop(); expected++; }
    return (expected-1)==n;
}

int main(){
    queue<int> q; int a[]={5,1,2,3,4};
    for(int x: a) q.push(x);
    cout << (canBeSorted(q)? "Yes":"No") << "\n";
    return 0;
}