#include<bits/stdc++.h>
using namespace std;
struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

bool isIdentical(Node* r1, Node* r2) {
        // code here
    if(r1== nullptr && r2== nullptr) return true;
    
    if(r1== nullptr || r2== nullptr) return false;
    
    
    if((r1->data == r2->data)&&(isIdentical(r1->left, r2->left))&&(isIdentical(r1->right, r2->right))){
        return true;
    }
        
     
}

int main(){

    return 0;
}