#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int new_val){
        data = new_val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertion(Node* root, int x){

    if(root == nullptr){
        Node* newNode = new Node(x);
        return newNode;
    }

    queue<Node*>q;
    q.push(root);
    Node* curr;
     while (!q.empty()) {
      
        Node* curr = q.front();
        q.pop();
	
        if (curr->left != nullptr)
            q.push(curr->left);
        else {
            curr->left = new Node(x);
            return root;
        }
	
        if (curr->right != nullptr)
            q.push(curr->right);
        else {
            curr->right = new Node(x);
            return root;
        }
    }
}

void inorder(Node* root){

    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    
    int n;
    cin>>n;
    Node* root = nullptr;
    while(n--){
        int x;
        cin>>x;
        root = insertion(root,x);

    }

    inorder(root);
    cout<<"\n";
    return 0;
}