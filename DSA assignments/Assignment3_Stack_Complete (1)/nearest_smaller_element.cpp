// nearest_smaller_element.cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nearestSmaller(vector<int> a){
    vector<int> res(a.size(),-1);
    stack<int> st;
    for(int i=0;i<a.size();i++){
        while(!st.empty() && st.top()>=a[i]) st.pop();
        if(!st.empty()) res[i]=st.top();
        st.push(a[i]);
    }
    return res;
}
int main(){
    vector<int> a={4,5,2,10,8};
    auto r=nearestSmaller(a);
    for(int x:r) cout<<x<<" ";
    cout<<"\n";
    return 0;
}