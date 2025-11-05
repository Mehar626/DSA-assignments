// queue_generate_binary.cpp
// Generate binary numbers from 1 to n using queue
#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n){
    queue<string> q;
    q.push("1");
    for(int i=1;i<=n;i++){
        string s = q.front(); q.pop();
        cout<<s << (i==n? "":" ");
        q.push(s + "0");
        q.push(s + "1");
    }
    cout<<"\n";
}

int main(){ generateBinary(10); return 0; }