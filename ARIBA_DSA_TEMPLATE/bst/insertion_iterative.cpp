#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    
    if(root == nullptr){
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }

    TreeNode* curr = root;
    while(curr!=nullptr){

        if(curr->right!=nullptr && val>curr->val) curr= curr->right;
        else if(curr->left!=nullptr && val<curr->val) curr=curr->left;
        else break;
    }
    if(curr!= nullptr && val<curr->val){
        curr->left = new TreeNode(val);
        return root;
    }

    curr->right = new TreeNode(val);
    return root;
}

int main(){
    return 0;
}