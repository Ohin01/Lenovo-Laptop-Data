#include<bits/stdc++.h>
using namespace std;

struct Node{

    int val;
    Node* left;
    Node* right;

    Node(int new_val){
        val = new_val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertion(Node* root, int x){

    if(root==nullptr){
        Node* newNode = new Node(x);
        return newNode;
    }

    else if(x<=root->val) root->left = insertion(root->left,x);
    else if(x>root->val) root->right = insertion(root->right,x);
    return root;
}

bool search(Node* root, int x){

    if(root == nullptr) return false;
    Node* curr = root;

    while(curr!=nullptr){
        if(curr->val == x) return true;
        else if(x<curr->val) curr = curr->left;
        else curr= curr->right;
    }
    return false;
}

int min(Node* root){

    if(root == nullptr) return -1;

    Node* curr= root;
    while(curr->left!=nullptr){
        curr = curr->left;
    }

    return curr->val;
}
// int minValue(Node* root) {
    
//     // If left child is null, root is minimum
//     if (root->left == nullptr) return root->data;
    
//     // Recurse on left child
//     return minValue(root->left);
// }

int max(Node* root){

    if(root==nullptr) return -1;
    Node* curr = root;
    while(curr->right!=nullptr){
        curr= curr->right;
    }
    return curr->val;
}

int floor(Node* root, int x){
     if(root == nullptr) return -1;
        else if(x< min(root)) return -1;
        
       Node* curr = root;
       int floor =-1;
       
       while(curr!=nullptr){
           
           if(curr->val == x) return x;
           else if(curr->val< x) {
               floor = curr->val;
               curr= curr->right;
           }
           else{ 
               curr = curr->left;
           }
       }
       
       return floor;
}


int ceil(Node* root, int x){

    if(root == nullptr) return -1;
    
    Node* curr = root;
    int ceil =-1;
    
    while(curr!=nullptr){
        if(curr->val == x) return x;
        else if(curr->val> x) {
            ceil = curr->val;
            curr= curr->left;
        }
        else{ 
            curr = curr->right;
        }
    }
    
    return ceil;
}

Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

Node* delNode(Node* root, int x){

     if (root == nullptr)
        return root;

    if (root->val > x)
        root->left = delNode(root->left, x);
    else if (root->val < x)
        root->right = delNode(root->right, x);
    else {
        // Node with 0 or 1 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children
        Node* succ = getSuccessor(root);
        root->val = succ->val;
        root->right = delNode(root->right, succ->val);
    }
    return root;
}

int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
    if(root == nullptr) return -1;
    
    Node* curr = root;
    int suc =-1;
    while(curr!=nullptr){
        if(x->val < curr->val){
            suc = curr->val;
            curr = curr->left;
        }
        
        else curr = curr->right;
    }
    return suc;
}

int inOrderPredecessor(Node *root, Node *x) {
        // Your code here
    if(root == nullptr) return -1;
    
    Node* curr = root;
    int pre =-1;
    while(curr!=nullptr){
        if(x->val > curr->val){
            pre = curr->val;
            curr = curr->right;
        }
        
        else curr = curr->left;
    }
    return pre;
}

void inorder(Node* root){

    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    
    int n;
    cin>>n;
    int target;
    cin>>target;

    Node* root = nullptr;

    while(n--){
        int x;
        cin>>x;
        root = insertion(root, x);
    }
    inorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    // cout<<search(root,target)<<"\n";
   
    return 0;
}