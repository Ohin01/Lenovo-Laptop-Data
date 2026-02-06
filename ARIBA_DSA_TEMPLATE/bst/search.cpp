#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool search(Node* root, int key) {
    // code here
    if(root == nullptr) return false;
    
    else if(root->data == key) return true;
    
    if(key>root->data) return search(root->right, key);
    else if(key<root->data) return search(root->left,key);
    
}
int main(){
    return 0;
}