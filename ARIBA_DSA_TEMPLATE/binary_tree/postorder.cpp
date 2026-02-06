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

 vector<int>postorder(TreeNode* root, vector<int>res){

    if(root == nullptr) return res;

    res = postorder(root->left, res);
    res = postorder(root->right, res);
    res.push_back(root->val);

    return res;
        
}
vector<int> postorderTraversal(TreeNode* root) {
    
    vector<int> res;

    res = postorder(root, res);
    return res;
}

int main(){

    return 0;
}