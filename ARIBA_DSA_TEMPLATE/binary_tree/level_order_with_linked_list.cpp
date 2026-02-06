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

vector<vector<int>> levelOrderTraversal(Node* root, vector<vector<int>> res, int level){
        
    if(root == nullptr) return res;
    
    if(res.size()== level) res.push_back({});
    
    res[level].push_back(root->data);
    
    res = levelOrderTraversal(root->left, res, level+1);
    
    res = levelOrderTraversal(root->right, res, level+1);
    
    return res;
}

vector<vector<int>> levelOrder(Node *root) {
    
    vector<vector<int>> res;
    
    res = levelOrderTraversal(root, res, 0);
    
    return res;
}

int main(){

    return 0;
}