// matrix_to_dll.cpp
// Convert 2D matrix to 4-directional doubly-linked structure (up/down/left/right)
#include <iostream>
#include <vector>
using namespace std;
struct Node{ int val; Node* left; Node* right; Node* up; Node* down; Node(int v):val(v),left(NULL),right(NULL),up(NULL),down(NULL){} };
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int r = mat.size(), c = mat[0].size();
    vector<vector<Node*>> nodes(r, vector<Node*>(c, NULL));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) nodes[i][j] = new Node(mat[i][j]);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        if(j+1<c) nodes[i][j]->right = nodes[i][j+1];
        if(j-1>=0) nodes[i][j]->left = nodes[i][j-1];
        if(i+1<r) nodes[i][j]->down = nodes[i+1][j];
        if(i-1>=0) nodes[i][j]->up = nodes[i-1][j];
    }
    // print row-wise using right pointers
    Node* row = nodes[0][0];
    Node* cur = row;
    while(cur){ cout<<cur->val; if(cur->right) cout<<" "; cur=cur->right; } cout<<"\n";
    return 0;
}