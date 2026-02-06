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

struct OhinQueue
{
    Node *cur;
    Node *rear;
    int cnt;

    OhinQueue(int n)
    {
        cur = NULL;
        rear = NULL;
        cnt = 0;
    }

    void push(int num)
    {
        Node *tmp = new Node(num);
        
        if (cnt == 0)
        {
            cur = tmp;
            rear = tmp;
        }

        else
        {
            rear->next = tmp;
            rear = rear->next;
        }

        cnt++;
    }

    void pop()
    {
        if (cnt == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node *dlt = cur;
        cur = cur->next;
        cnt--;
        delete dlt;

        if (cnt == 0)
        {
            cur = NULL;
            rear = NULL;
        }
    }

    int front()
    {
        if (cnt == 0) return -1;

        return cur->data;
    }

    bool isEmpty()
    {
        if (cnt == 0) return true;
        else return false;
    }

    int size()
    {
        return cnt;
    }

    void print()
    {
        Node *it = cur;

        while (it != NULL)
        {
            cout << it->data << endl;
            it = it->next;
        }
    }
};

int main(void)
{
    
}
