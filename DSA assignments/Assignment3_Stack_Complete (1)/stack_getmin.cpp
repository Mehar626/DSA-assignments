// stack_getmin.cpp
#include <iostream>
#include <stack>
using namespace std;
class MinStack{
    stack<int> s, smin;
public:
    void push(int x){ s.push(x); if(smin.empty()||x<=smin.top()) smin.push(x); }
    void pop(){ if(s.top()==smin.top()) smin.pop(); s.pop(); }
    int top(){ return s.top(); }
    int getMin(){ return smin.top(); }
};
int main(){
    MinStack s; s.push(5); s.push(2); s.push(8);
    cout<<"Min: "<<s.getMin()<<"\n"; s.pop(); cout<<"Min: "<<s.getMin()<<"\n";
    return 0;
}