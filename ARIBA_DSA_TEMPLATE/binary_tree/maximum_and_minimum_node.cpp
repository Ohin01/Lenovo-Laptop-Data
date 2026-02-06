#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int max(Node* root, int l){
        
    if(root== nullptr) return l;
    
    l = max(root->left, l);
    
    if(root->data >l) l = root->data;
    
    l = max(root->right, l);
    
    return l;
}

int findMax(Node *root) {
    // code here
    
    int l = -1;
    
    l = max(root, l);
    
    return l;
}

int min(Node* root, int s){
    
    if(root== nullptr) return s;
    
    s = min(root->left, s);
    
    if(root->data <s) s = root->data;
    
    s = min(root->right, s);
    
    return s;
}

int findMin(Node* root) {
    
    // code here
    
    int s = 1000000;
    
    s = min(root, s);
    
    return s;
}

int main(){

    return 0;
}