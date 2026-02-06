#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

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

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->right->right = new Node(4);
    
     vector<int>p(6,0);
  
  parent(root, p);
  
  for(int d: p){
    
    cout<<d<<" ";
  }
    return 0;
}