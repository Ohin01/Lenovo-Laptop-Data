#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node (int x) 
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
struct OhinStack
{
    vector<T> arr;
    int cur;
    int cap;

    OhinStack(int n)
    {
        arr.resize(n + 1);
        cur = -1;
    }

    void push(T num)
    {
        cur++;
        arr[cur] = num;
    }

    void pop()
    {
        cur--;
    }

    T top()
    {
        if (cur == -1) return NULL;

        return arr[cur];
    }

    bool empty()
    {
        if (cur == -1) return true;
        else return false;
    }

    int size()
    {
        return top + 1;
    }
};

Node* insert(Node *root, int key)
{
    if (root == NULL)
    return new Node(key);

    if (key <= root->data)
    {
        root->left = insert(root->left, key);
    }

    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

vector<int> merge(Node *root1, Node *root2, int n1, int n2) 
{
    vector<int> res;
    OhinStack<Node*> st1(n1), st2(n2);
    
    while (root1 != NULL || root2 != NULL || st1.empty() == false || st2.empty() == false) 
    {
        while (root1 != NULL) 
        {
            st1.push(root1);
            root1 = root1->left;
        }
        
        while (root2 != NULL)
        {
            st2.push(root2);
            root2 = root2->left;
        }
        
        if (st2.empty() == true)
        {
            root1 = st1.top();
            st1.pop();
            res.push_back(root1->data);
            root1 = root1->right;
        }

        else if (st1.empty() == false && (st1.top()->data <= st2.top()->data))
        {
            root1 = st1.top();
            st1.pop();
            res.push_back(root1->data);
            root1 = root1->right;
        }

        else 
        {
            root2 = st2.top();
            st2.pop();
            res.push_back(root2->data);
            root2 = root2->right;
        }
    }
    
    return res;
}

int main() 
{
    Node* root1 = NULL;
    Node* root2 = NULL;

    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int num;
        cin >> num;

        root1 = insert(root1, num);
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int num;
        cin >> num;

        root2 = insert(root2, num);
    }
    
    vector<int> res = merge(root1, root2, n1, n2);
    for (int i = 0; i < res.size() - 1; i++)
    cout << res[i] << " ";
    cout << res[res.size() - 1];
    cout << endl;
}
