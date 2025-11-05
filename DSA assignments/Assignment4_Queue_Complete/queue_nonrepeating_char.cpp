// queue_nonrepeating_char.cpp
// First non-repeating character in stream using queue
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void firstNonRepeating(string s){
    queue<char> q;
    vector<int> count(256,0);
    for(char c: s){
        count[c]++;
        q.push(c);
        while(!q.empty() && count[q.front()]>1) q.pop();
        if(q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << "\n";
}

int main(){
    string s = "aabcbc";
    firstNonRepeating(s);
    // output: a -1 b b c -1 (depending on input)
    return 0;
}