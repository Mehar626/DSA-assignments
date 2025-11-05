// reverse_string_stack.cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string str="HELLO";
    stack<char> s;
    for(char c:str) s.push(c);
    string rev="";
    while(!s.empty()){ rev+=s.top(); s.pop(); }
    cout<<"Original: "<<str<<"\nReversed: "<<rev<<"\n";
    return 0;
}