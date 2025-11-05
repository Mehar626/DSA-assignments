// Q4 – Check if a Binary Tree is a BST
#include <iostream>
#include <climits>
using namespace std;

/*
Detailed Logic:
1️⃣ To verify BST, ensure every node value lies within valid range (min,max).
2️⃣ For left child, update max = current node’s value.
3️⃣ For right child, update min = current node’s value.
4️⃣ Recursively check all subtrees.
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=nullptr; }
};

class Tree {
public:
    Node* createSampleTree(bool validBST=true){
        Node* root=new Node(10);
        if(validBST){
            root->left=new Node(5);
            root->right=new Node(15);
        } else {
            root->left=new Node(20);
            root->right=new Node(5);
        }
        return root;
    }

    bool isBST(Node* root,int minVal,int maxVal){
        if(!root) return true;
        if(root->data <= minVal || root->data >= maxVal) return false;
        return isBST(root->left,minVal,root->data) && isBST(root->right,root->data,maxVal);
    }
};

int main(){
    Tree t;
    Node* valid = t.createSampleTree(true);
    Node* invalid = t.createSampleTree(false);

    cout<<"Valid tree: "<<(t.isBST(valid,INT_MIN,INT_MAX)?"BST":"Not BST")<<"\n";
    cout<<"Invalid tree: "<<(t.isBST(invalid,INT_MIN,INT_MAX)?"BST":"Not BST")<<"\n";
}
