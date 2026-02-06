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

struct OhinStack
{
    Node *cur;
    int cnt;

    OhinStack(int n)
    {
        cur = NULL;
        cnt = 0;
    }

    void push(int num)
    {
        Node *tmp = new Node(num);
        tmp->next = cur; 
        cur = tmp;
        cnt++;
    }

    void pop()
    {
        if (cur == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        Node *dlt = cur;
        cur = cur->next;
        cnt--;
        delete dlt;
    }

    int top()
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
    OhinStack st(10);

    st.push(1);
    st.push(2);

    st.print();
}
