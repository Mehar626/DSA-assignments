// queue_sort.cpp
// Sort a queue without using extra space (uses only queue operations)
#include <iostream>
#include <queue>
using namespace std;

// Simple selection sort like approach using only queue ops
void sortQueue(queue<int> &q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int minVal = INT_MAX;
        // find min in remaining n-i elements
        for(int j=0;j<n-i;j++){
            int x = q.front(); q.pop();
            if(x < minVal) minVal = x;
            q.push(x);
        }
        // move elements, put min at end (n-i)th position
        bool minPlaced = false;
        for(int j=0;j<n-i;j++){
            int x = q.front(); q.pop();
            if(x == minVal && !minPlaced){ q.push(x); minPlaced = true; }
            else q.push(x);
        }
        // rotate first i elements to front
        for(int j=0;j<i;j++){ q.push(q.front()); q.pop(); }
    }
    // After this algorithm, queue will be sorted in ascending order (front smallest)
}

int main(){
    queue<int> q; int a[]={11,5,4,21};
    for(int x: a) q.push(x);
    sortQueue(q);
    while(!q.empty()){ cout<<q.front()<<(q.size()? " ":""); q.pop(); }
    cout<<"\n";
    return 0;
}