// queue_circular.cpp
// Circular queue implementation (array based)
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr; int capacity, frontIndex, rearIndex, count;
public:
    CircularQueue(int size=10) {
        capacity=size; arr=new int[capacity]; frontIndex=0; rearIndex=-1; count=0;
    }
    ~CircularQueue(){ delete[] arr; }
    bool isEmpty(){ return count==0; }
    bool isFull(){ return count==capacity; }
    void enqueue(int x){ if(isFull()){ cout<<"Full\n"; return; } rearIndex=(rearIndex+1)%capacity; arr[rearIndex]=x; count++; cout<<x<<" enqueued\n"; }
    int dequeue(){ if(isEmpty()){ cout<<"Empty\n"; return -1; } int v=arr[frontIndex]; frontIndex=(frontIndex+1)%capacity; count--; return v; }
    int peek(){ if(isEmpty()){ cout<<"Empty\n"; return -1; } return arr[frontIndex]; }
    void display(){ if(isEmpty()){ cout<<"Empty\n"; return; } cout<<"Queue: "; for(int i=0, idx=frontIndex;i<count;i++,idx=(idx+1)%capacity) cout<<arr[idx]<<(i+1==count?"":" "); cout<<"\n"; }
};

int main(){ CircularQueue q(6); q.enqueue(1); q.enqueue(2); q.enqueue(3); q.display(); cout<<"Dequeue: "<<q.dequeue()<<"\n"; q.display(); return 0; }