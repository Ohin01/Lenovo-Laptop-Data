#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth(Node* root){

     if(root == nullptr) return 0;
        
    int left_height = maxDepth(root -> left);
    int right_height = maxDepth(root -> right);
    
    return max(left_height, right_height)+1;
}

int main(){

    return 0;
}