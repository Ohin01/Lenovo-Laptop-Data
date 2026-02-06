#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *bst;

    Node(int key)
    {
        val = key;
        left = NULL;
        right = NULL;
        bst = NULL;
    }
};

struct BST
{
    Node *root;

    BST()
    {
        root = NULL;
    }
    
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

    void inorder(Node *root)
    {
        if (root == NULL)
        return;

        inorder(root->left);
        
        cout << root->val << endl;

        inorder(root->right);
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

Node *find(Node *root, int key)
{
    if (root == NULL)
    return NULL;

    if (key == root->val)
    return root;

    else if (key < root->val)
    return find(root->left, key);

    else
    return find(root->right, key);
}

void printBST(Node *root, vector<int> &tmp)
{
    if (root == NULL)
    return;

    printBST(root->left, tmp);
    
    tmp.push_back(root->val);

    printBST(root->right, tmp);
}

void inorder(Node *root)
{
    if (root == NULL)
    return;

    inorder(root->left);

    vector<int> tmp;
    
    printBST(root->bst, tmp);
    
    for (int i = 0; i < tmp.size() - 1; i++)
    cout << tmp[i] << " ";
    cout << tmp[tmp.size() - 1];
    cout << endl;

    inorder(root->right);
}




int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int m = arr[i] % k;

        Node *f = find(root, m);

        if (f == NULL)
        {
            root = insert(root, m);
            f = find(root, m);
            f->bst = insert(f->bst, arr[i]);
        }

        else
        {
            f->bst = insert(f->bst, arr[i]);
        }
    }   

    inorder(root);



    return 0;
}