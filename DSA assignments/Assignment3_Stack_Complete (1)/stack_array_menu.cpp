// stack_array_menu.cpp
// Menu-driven Stack implementation using array
#include <iostream>
using namespace std;

class Stack {
    int *arr, top, capacity;
public:
    Stack(int size=100){ capacity=size; arr=new int[capacity]; top=-1; }
    ~Stack(){ delete[] arr; }
    bool isEmpty(){ return top==-1; }
    bool isFull(){ return top==capacity-1; }
    void push(int val){ if(isFull()){ cout<<"Stack Overflow\n"; return;} arr[++top]=val; cout<<val<<" pushed\n"; }
    void pop(){ if(isEmpty()){ cout<<"Stack Underflow\n"; return;} cout<<arr[top--]<<" popped\n"; }
    void peek(){ if(isEmpty()){ cout<<"Stack Empty\n"; return;} cout<<"Top: "<<arr[top]<<"\n"; }
    void display(){ if(isEmpty()){ cout<<"Empty\n"; return;} cout<<"Stack: "; for(int i=top;i>=0;i--) cout<<arr[i]<<" "; cout<<"\n"; }
};

int main(){
    Stack s(10);
    int ch,v;
    do{
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 0.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter value: ";cin>>v; s.push(v);break;
            case 2: s.pop();break;
            case 3: s.peek();break;
            case 4: s.display();break;
        }
    }while(ch!=0);
    return 0;
}