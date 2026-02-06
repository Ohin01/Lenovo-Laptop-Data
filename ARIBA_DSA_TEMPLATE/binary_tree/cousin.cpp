#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//parent array
void parent(Node* root, vector<int>&p){
  
  if(root== nullptr) return ;
 
  if(root->left!= nullptr){
    
    //cout<<root->left->data<<"\n";
    p[root->left->data] = root->data;
    parent(root->left, p);
    
  }
  
  if(root->right!= nullptr){
    
     //out<<root->right->data<<"\n";
    p[root->right->data] = root->data;
    parent(root->right, p);
    
  }
   
}

//depth array
void traversal(Node* node, vector<int>&depth, int level){
  
  if(node == nullptr) return;
  
  traversal(node->left, depth, level+1);
  
  traversal(node->right, depth, level+1);
  
  depth[node->data] = level;
  
}

bool isCousins(Node* root, int x, int y) {
        

    vector<int>d(100001,0);
    vector<int>p(100001,0);
    
    traversal(root, d, 0);
    parent(root, p);
    
    if((d[x]==d[y]) && (p[x]!= p[y])) return true;
    
    return false;
}

int main(){

    return 0;
}