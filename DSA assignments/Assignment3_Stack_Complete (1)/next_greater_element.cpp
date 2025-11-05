// next_greater_element.cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreater(vector<int> a){
    int n=a.size(); vector<int> res(n,-1); stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=a[i]) st.pop();
        if(!st.empty()) res[i]=st.top();
        st.push(a[i]);
    }
    return res;
}
int main(){
    vector<int> a={4,5,2,25};
    auto r=nextGreater(a);
    for(int x:r) cout<<x<<" ";
    cout<<"\n";
    return 0;
}