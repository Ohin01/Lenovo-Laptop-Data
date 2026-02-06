#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }

};

bool isMirror(Node* root1,Node* root2){
    
    if(root1 == nullptr && root2== nullptr) return true;
    else if(root1 != nullptr && root2 == nullptr) return false;
    else if(root1 == nullptr && root2 != nullptr) return false;
    
    return isMirror(root1->left, root2->right) &&
    isMirror(root1->right, root2->left);
    
}


bool IsFoldable(Node* root) {
    // Your code goes here
    if(root == nullptr) return true;
    
    return isMirror(root->left, root->right);
}

int main(){

    return 0;
}