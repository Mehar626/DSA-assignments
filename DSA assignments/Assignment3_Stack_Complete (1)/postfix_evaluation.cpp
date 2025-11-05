// postfix_evaluation.cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int evaluatePostfix(string exp){
    stack<int> st;
    for(char c:exp){
        if(isdigit(c)) st.push(c-'0');
        else{
            int v2=st.top(); st.pop();
            int v1=st.top(); st.pop();
            switch(c){
                case '+': st.push(v1+v2); break;
                case '-': st.push(v1-v2); break;
                case '*': st.push(v1*v2); break;
                case '/': st.push(v1/v2); break;
            }
        }
    }
    return st.top();
}
int main(){
    string exp="231*+9-";
    cout<<"Result: "<<evaluatePostfix(exp)<<"\n";
    return 0;
}