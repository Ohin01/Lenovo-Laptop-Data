#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> preOrder(Node* root) {
    // code here
    vector<int>res;
    stack<Node*>s;
    Node* curr=root;
    while(curr!=nullptr || !s.empty()){
        //if(curr!= nullptr)res.push_back(curr->data);
        while(curr!=nullptr){
            res.push_back(curr->data);
            s.push(curr);
            curr=curr->left;
        }
        
        curr= s.top();
        s.pop();
        curr=curr->right;
    }
    return res;
}

int main(){

    
    return 0;
}