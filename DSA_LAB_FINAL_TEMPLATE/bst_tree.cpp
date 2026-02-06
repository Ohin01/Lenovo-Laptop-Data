#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int key)
    {
        val = key;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, int key)
{
    if (root == NULL)
    return new Node(key);

    if (key <= root->val)
    {
        root->left = insert(root->left, key);
    }

    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

bool search(Node *root, int key)
{
    if (root == NULL)
    return false;

    if (key == root->val)
    return true;

    else if (key < root->val)
    return search(root->left, key);

    else
    return search(root->right, key);
}

Node *findMin(Node *root)
{
    if (root == NULL)
    return root;

    if (root->left != NULL)
    return findMin(root->left);

    else 
    return root;
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

        Node* succ = getSuccessor(root);
        root->val = succ->val;
        root->right = delNode(root->right, succ->val);
    }
    return root;
}

int floor(Node* root, int x) {
  
    int floorValue = -1;

    while (root != nullptr) {
    
        if (root->val == x) {
            return root->val;
        }

        if (root->val > x) {
            root = root->left;
        } 
        else {
            floorValue = root->val;
            root = root->right;
        }
    }

    return floorValue;
}


int findCeil(Node* root, int key) {
  
    int ceil = -2; 

    while (root) {
        if (root->val == key) {
            return root->val; 
        }
 
        if (key > root->val) {
            root = root->right; 
        } 
      
        else {
            ceil = root->val; 
            root = root->left; 
        }
    }
    return ceil; 
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

void inorder(Node *root)
{
    if (root == NULL)
    return;

    inorder(root->left);
    
    cout << root->val << endl;

    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    return;

    cout << root->val << endl;

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    return;

    postorder(root->left);

    postorder(root->right);

    cout << root->val << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    root = delNode(root, 12);

    inorder(root);



    return 0;
}