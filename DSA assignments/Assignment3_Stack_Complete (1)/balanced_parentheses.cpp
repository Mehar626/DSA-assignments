// balanced_parentheses.cpp
#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{') st.push(c);
        else if(c==')'||c==']'||c=='}'){
            if(st.empty()) return false;
            char t=st.top(); st.pop();
            if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{')) return false;
        }
    }
    return st.empty();
}
int main(){
    string s="{[()]}";
    cout<<(isBalanced(s)? "Balanced":"Not Balanced")<<"\n";
    return 0;
}