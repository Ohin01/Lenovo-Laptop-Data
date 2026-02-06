#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    int h;

    Node(int num)
    {
        val = num;
        left = NULL;
        right = NULL;
        h = 1;
    }
};

int findHeight(Node *head)
{
    if (head == NULL)
    return 0;

    else
    return head->h;
}

int balance_factor(Node *head)
{
    if (head == NULL)
    return 0;

    return findHeight(head->left) - findHeight(head->right);
}

Node *right_rotate(Node *head)
{
    if (head == NULL)
    return head;

    Node *prevHead = head;
    head = head->left;

    Node *prevRight = head->right;
    head->right = prevHead;
    prevHead->left = prevRight;

    prevHead->h = max(findHeight(prevHead->left), findHeight(prevHead->right)) + 1;
    head->h = max(findHeight(head->left), findHeight(head->right)) + 1;
    
    return head;
}

Node *left_rotate(Node *head)
{
    if (head == NULL)
    return NULL;

    Node *prevHead = head;
    head = head->right;

    Node *prevLeft = head->left;
    head->left = prevHead;
    prevHead->right = prevLeft;

    prevHead->h = max(findHeight(prevHead->left), findHeight(prevHead->right)) + 1;
    head->h = max(findHeight(head->left), findHeight(head->right)) + 1;

    return head;
}

Node *insert(Node *head, int num)
{
    Node *node = new Node(num);

    if (head == NULL)
    {
        head = node;
        return head;
    }

    if (num < head->val)
    {
        head->left = insert(head->left, num);
    }

    else
    {
        head->right = insert(head->right, num);
    }

    head->h = max(findHeight(head->left), findHeight(head->right)) + 1;

    int bf = balance_factor(head);

    if (bf > 1 && num < head->left->val)
    {
        head = right_rotate(head);
    }

    else if (bf > 1 && num >= head->left->val)
    {
        head->left = left_rotate(head->left);
        head = right_rotate(head);
    }

    else if (bf < -1 && num >= head->right->val)
    {
        head = left_rotate(head);
    }

    else if (bf < -1 && num < head->right->val)
    {
        head->right = right_rotate(head->right);
        head = left_rotate(head);
    }

    return head;
}

void infix(Node *head)
{
    if (head == NULL)
    return;

    infix(head->left);
    
    cout << head->val << endl;

    infix(head->right);
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;

    while(n--)
    {
        int num;
        cin >> num;

        head = insert(head, num);
    }

    infix(head);
}