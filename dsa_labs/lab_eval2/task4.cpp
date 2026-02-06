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

int cnt = 0;

int findHeight(Node *root)
{
    if (root == NULL)
    return 0;

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    if (abs(left - right) <= 2)
    cnt++;

    return max(left, right) + 1;
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

    int mx = findHeight(root);

    //cout << mx << endl;

    cout << cnt;

    return 0;
}