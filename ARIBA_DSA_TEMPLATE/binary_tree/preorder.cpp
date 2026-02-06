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

 vector<int>preorder(TreeNode* root, vector<int>res){

        if(root == nullptr) return res;

        res.push_back(root->val);
        res = preorder(root->left, res);
        res = preorder(root->right, res);

        return res;
        
    }
vector<int> preorderTraversal(TreeNode* root) {
    
    vector<int> res;

    res = preorder(root, res);
    return res;
}

int main(){

    return 0;
}