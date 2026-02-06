#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> postOrder(Node* root) {
    // code here
   vector<int>res;
        if(root==nullptr) return res;
   stack<Node*>s1;
   stack<Node*>s2;
    Node* curr ;
   s1.push(root);
   while(!s1.empty()){

    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if(curr->left!=nullptr) s1.push(curr->left);
    if(curr->right!=nullptr) s1.push(curr->right);
   }

   while(!s2.empty()){
    res.push_back(s2.top()->data);
    s2.pop();
   }
   return res;
}

int main(){

    
    return 0;
}