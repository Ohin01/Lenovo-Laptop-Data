#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int num)
    {
        data = num;
        next = NULL;
    }
};

Node *insertFront(Node *head, int num)
{
    Node *tmp = new Node(num);

    if (head == NULL)
    {
        return tmp;
    }

    tmp->next = head;
    head = tmp;
    return head;
}

Node *insertTail(Node *tail, int num)
{
    Node *tmp = new Node(num);

    tail->next = tmp;
    tail = tail->next;

    return tail;
}

// Node *insertBack(Node *head, int num)
// {
//     Node *tmp = new Node(num);

//     if (head == NULL) return tmp;

//     Node *it = head;

//     while (it->next != NULL)
//     it = it->next;

//     it->next = tmp;

//     return head;
// }

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int p, v;
        cin >> p >> v;

        if (i == 0)
        {
            Node *neww = new Node(v);
            head = neww;
            tail = neww;
            continue;
        }

        if (p == 0)
        {
            head = insertFront(head, v);
        }

        else
        {
            tail = insertTail(tail, v);
        }
    }

    Node *it = head;

    while (it != NULL)
    {
        cout << it->data << endl;
        it = it->next;
    }
}