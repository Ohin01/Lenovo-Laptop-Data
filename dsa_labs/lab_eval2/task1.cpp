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

Node *insert(Node *root, queue<Node*>&q, int value)
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

vector<int> all;

void mirrorPreorder(Node *root)
{
    if (root == NULL)
    return;

    all.push_back(root->val);

    mirrorPreorder(root->right);

    mirrorPreorder(root->left);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    cin >> a[i];

    Node *root = NULL;
    queue<Node*> q;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, q, a[i]);
    }

    //cout << root->val << endl;

    mirrorPreorder(root);

    for (int i = 0; i < all.size() - 1; i++)
    cout << all[i] << " ";

    cout << all[all.size() - 1] << endl;

    return 0;

}