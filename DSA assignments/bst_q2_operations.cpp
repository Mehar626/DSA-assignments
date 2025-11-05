// Q2 – BST Operations (Search, Min, Max, Successor, Predecessor)
#include <iostream>
using namespace std;

/*
Detailed Logic:
1️⃣ BST Property: Left subtree < Root < Right subtree.
2️⃣ Recursive search: Traverse left or right based on comparison.
3️⃣ Iterative search: Same logic without recursion.
4️⃣ Find Min: Go to extreme left (smallest value).
5️⃣ Find Max: Go to extreme right (largest value).
6️⃣ Inorder Successor: Smallest node greater than key.
7️⃣ Inorder Predecessor: Largest node smaller than key.
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

    bool searchRecursive(Node* root, int key){
        if(!root) return false;
        if(root->data == key) return true;
        if(key < root->data) return searchRecursive(root->left, key);
        else return searchRecursive(root->right, key);
    }

    bool searchIterative(Node* root, int key){
        while(root){
            if(root->data == key) return true;
            else if(key < root->data) root = root->left;
            else root = root->right;
        }
        return false;
    }

    int findMin(Node* root){
        while(root->left) root = root->left;
        return root->data;
    }

    int findMax(Node* root){
        while(root->right) root = root->right;
        return root->data;
    }

    Node* findInorderSuccessor(Node* root, int key){
        Node* successor = nullptr;
        while(root){
            if(key < root->data){
                successor = root;
                root = root->left;
            } else root = root->right;
        }
        return successor;
    }

    Node* findInorderPredecessor(Node* root, int key){
        Node* predecessor = nullptr;
        while(root){
            if(key > root->data){
                predecessor = root;
                root = root->right;
            } else root = root->left;
        }
        return predecessor;
    }
};

int main(){
    BST tree;
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for(int x: arr) root = tree.insert(root, x);

    cout << "Search (recursive) 40: " << (tree.searchRecursive(root,40)?"Found":"Not found") << "\n";
    cout << "Search (iterative) 90: " << (tree.searchIterative(root,90)?"Found":"Not found") << "\n";
    cout << "Min: " << tree.findMin(root) << ", Max: " << tree.findMax(root) << "\n";

    Node* suc = tree.findInorderSuccessor(root, 40);
    Node* pre = tree.findInorderPredecessor(root, 40);
    cout << "Successor of 40: " << (suc ? suc->data : -1) << "\n";
    cout << "Predecessor of 40: " << (pre ? pre->data : -1) << "\n";
}
