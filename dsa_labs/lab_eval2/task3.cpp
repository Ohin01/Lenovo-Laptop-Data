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

void levelOrder(Node *root, vector<vector<int>> &alldepth)
{
    if (root == NULL)
    return;

    queue<Node*>q;

    q.push(root);

    int depth = 1;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp;

        for (int i = 0; i < sz; i++)
        {
            Node *cur = q.front();
            temp.push_back(cur->val);
            q.pop();

            if (cur->left != NULL)
            q.push(cur->left);

            if (cur->right != NULL)
            q.push(cur->right);
        }

        alldepth.push_back(temp);

        depth++;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    return;

    inorder(root->left);
    
    cout << root->val << endl;

    inorder(root->right);
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

    vector<vector<int>> allDepth;
    allDepth.push_back({});

    levelOrder(root, allDepth);
    //inorder(root);

    int S, E;
    cin >> S >> E;

    int ans = 0;

    for (int i = S; i <= E; i++)
    {
        ans += allDepth[i].size();
    }

    cout << ans;
    return 0;
}