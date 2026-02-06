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

 vector<int>inorder(TreeNode* root, vector<int>res){

        if(root == nullptr) return res;

        res = inorder(root->left, res);
        res.push_back(root->val);
        res = inorder(root->right, res);

        return res;
        
    }
vector<int> inorderTraversal(TreeNode* root) {
    
    vector<int> res;

    res = inorder(root, res);
    return res;
}

int main(){

    return 0;
}