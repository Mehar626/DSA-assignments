// stack_using_queues.cpp
// Implement stack using two queues and one queue (method shown for two queues)
#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){ q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    int pop(){
        if(q1.empty()){ cout<<"Empty\n"; return -1; }
        int val = q1.front(); q1.pop(); return val;
    }
    int top(){ if(q1.empty()){ cout<<"Empty\n"; return -1; } return q1.front(); }
    bool empty(){ return q1.empty(); }
};

int main(){
    StackUsingTwoQueues s;
    s.push(10); s.push(20); s.push(30);
    cout<<s.pop()<<"\n"; cout<<s.top()<<"\n";
    return 0;
}