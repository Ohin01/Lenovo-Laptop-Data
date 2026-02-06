#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int num)
    {
        val = num;
        left = NULL;
        right = NULL;
    }
};

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

Node *insertLevelOrder(Node *root, queue<Node*>&q, int value)
{
    Node *neww = new Node(value);
    if (root == NULL)
    {
        q.push(neww);
        return neww;
    }

    Node *cur = q.front();

    if (cur->left == NULL)
    {
        cur->left = new Node(value);
        q.push(cur->left);
    }

    else
    {
        cur->right = new Node(value);
        q.push(cur->right);
        q.pop();
    }

    return root;
}

vector<vector<int>> levelOrder(Node* root) 
{        
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();

        vector<int> temp;

        for (int i = 0; i < sz; i++)
        {
            Node *topp = q.front();
            temp.push_back(topp->val);
            q.pop();

            if (topp->left != NULL)
            q.push(topp->left);

            if (topp->right != NULL)
            q.push(topp->right);
        }

        ans.push_back(temp);
    }

    return ans;
}

int findHeight(Node *root)
{
    if (root == NULL)
    return 0;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr)
        return true;

    queue<Node*> q;
    q.push(root);
    bool end = false; 

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            if (end) 
                return false;
            q.push(current->left);
        } 
       else {
            end = true;
        }

        
        if (current->right) {
            if (end) 
                return false;
          
            q.push(current->right);
        } 
       else {
            end = true;
        }
    }

    return true; 
}

int findDepth(Node* root, int x) {
    if (!root) 
        return -1;  // Node not found

    if (root->val == x) 
        return 0;   // Found at current node

    // Check left subtree
    int leftDist = findDepth(root->left, x);
    if (leftDist >= 0) 
        return leftDist + 1;

    // Check right subtree
    int rightDist = findDepth(root->right, x);
    if (rightDist >= 0) 
        return rightDist + 1;

    return -1;
}


int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    Node *root = NULL;
    queue<Node*>q;

    for (int i = 0; i < n; i++)
    {
        root = insertLevelOrder(root, q, arr[i]);
    }

    inorder(root);

    return 0;
}