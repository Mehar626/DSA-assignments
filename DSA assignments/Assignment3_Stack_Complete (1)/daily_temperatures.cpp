// daily_temperatures.cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temp){
    int n=temp.size(); vector<int> res(n,0); stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && temp[i]>temp[st.top()]){
            int idx=st.top(); st.pop();
            res[idx]=i-idx;
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> t={73,74,75,71,69,72,76,73};
    auto r=dailyTemperatures(t);
    for(int x:r) cout<<x<<" ";
    cout<<"\n";
    return 0;
}