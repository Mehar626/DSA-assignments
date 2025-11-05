// stack_sort_check.cpp
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool checkSorted(queue<int> q){
    stack<int> s; int expected=1;
    while(!q.empty()){
        if(q.front()==expected){ q.pop(); expected++; }
        else if(!s.empty() && s.top()==expected){ s.pop(); expected++; }
        else { s.push(q.front()); q.pop(); }
    }
    while(!s.empty() && s.top()==expected){ s.pop(); expected++; }
    return s.empty();
}
int main(){
    queue<int> q; int a[]={5,1,2,3,4}; for(int x:a) q.push(x);
    cout<<(checkSorted(q)? "Yes":"No")<<"\n"; return 0;
}