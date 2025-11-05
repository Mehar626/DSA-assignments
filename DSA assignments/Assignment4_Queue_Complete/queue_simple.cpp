// queue_simple.cpp
// Simple linear queue using array, beginner friendly
#include <iostream>
using namespace std;

class SimpleQueue {
    int *arr;
    int capacity;
    int frontIndex, rearIndex, count;
public:
    SimpleQueue(int size=100) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }
    ~SimpleQueue() { delete[] arr; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
    void enqueue(int x) {
        if (isFull()) { cout << "Queue is full\n"; return; }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
        cout << x << " enqueued\n";
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue empty\n"; return -1; }
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }
    int peek() {
        if (isEmpty()) { cout << "Queue empty\n"; return -1; }
        return arr[frontIndex];
    }
    void display() {
        if (isEmpty()) { cout << "Queue empty\n"; return; }
        cout << "Queue: ";
        for (int i=0, idx=frontIndex; i<count; ++i, idx = (idx+1)%capacity)
            cout << arr[idx] << (i+1==count? "":" ");
        cout << "\n";
    }
};

int main(){
    SimpleQueue q(10);
    q.enqueue(4); q.enqueue(7); q.enqueue(11);
    q.display();
    cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();
    cout << "Peek: " << q.peek() << "\n";
    return 0;
}