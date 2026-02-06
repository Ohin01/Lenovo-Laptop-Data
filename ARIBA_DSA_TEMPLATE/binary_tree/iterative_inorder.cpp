#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> inOrder(Node* root) {
       
    vector<int>res;
    stack<Node*>s;
    Node* curr = root;
    
    while(!s.empty() || curr!= nullptr){
        
        while(curr!=nullptr){
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();
        res.push_back(curr->data);
        curr = curr->right;
    }
    
    
    return res;
}

int main(){

    
    return 0;
}