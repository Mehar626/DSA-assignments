// Q3 – Insert, Delete, and Depth (Min & Max) in BST
#include <iostream>
using namespace std;

/*
Detailed Logic:
1️⃣ Insert: Use recursion, compare value and insert in correct subtree.
2️⃣ Delete:
   - If node has no children → delete directly.
   - If node has one child → link parent to that child.
   - If node has two children → replace data with inorder successor and delete that successor.
3️⃣ Depth (Height):
   - Max Depth = 1 + max(depth(left), depth(right))
   - Min Depth = 1 + min(depth(left), depth(right))
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=nullptr; }
};

class BST {
public:
    Node* insert(Node* root, int val){
        if(!root) return new Node(val);
        if(val < root->data) root->left = insert(root->left, val);
        else if(val > root->data) root->right = insert(root->right, val);
        return root;
    }

    Node* findMin(Node* root){
        while(root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key){
        if(!root) return root;
        if(key < root->data) root->left = deleteNode(root->left, key);
        else if(key > root->data) root->right = deleteNode(root->right, key);
        else {
            if(!root->left){ Node* temp=root->right; delete root; return temp; }
            else if(!root->right){ Node* temp=root->left; delete root; return temp; }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int maxDepth(Node* root){
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main(){
    BST t;
    Node* root=nullptr;
    int arr[]={50,30,70,20,40,60,80};
    for(int x:arr) root=t.insert(root,x);
    cout<<"Inorder before delete: "; t.inorder(root); cout<<"\n";
    root=t.deleteNode(root,20);
    cout<<"After deleting 20: "; t.inorder(root); cout<<"\n";
    cout<<"Max depth: "<<t.maxDepth(root)<<", Min depth: "<<t.minDepth(root)<<"\n";
}
