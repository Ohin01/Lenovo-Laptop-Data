#include<bits/stdc++.h>
using namespace std;

struct dNode
{
    int data;
    dNode* next;
    dNode* prev;

    dNode(int num)
    {
        data = num;
        next = NULL;
        prev = NULL;
    }
};

struct dDequeue
{
    dNode *fir = NULL;
    dNode *last = NULL;
    int count = 0;

    bool isEmpty()
    {
        return count == 0;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "No element\n";
            return -1;
        }
        return fir->data;
    }

    int back()
    {
        if (isEmpty())
        {
            cout << "No element\n";
            return -1;
        }
        return last->data;
    }

    void push_front(int num)
    {
        dNode *temp = new dNode(num);

        if (count == 0)
        {
            fir = last = temp;
        }
        else
        {
            temp->next = fir;
            fir->prev = temp;
            fir = temp;
        }
        count++;
    }

    void push_back(int num)
    {
        dNode *temp = new dNode(num);

        if (count == 0)
        {
            fir = last = temp;
        }
        else
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        count++;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Dequeue is empty\n";
            return;
        }

        dNode *pr = fir;
        fir = fir->next;
        count--;

        if (fir != NULL)
            fir->prev = NULL;
        else
            last = NULL;

        delete pr;
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Dequeue is empty\n";
            return;
        }

        dNode *pr = last;
        last = last->prev;
        count--;

        if (last != NULL)
            last->next = NULL;
        else
            fir = NULL;

        delete pr;
    }

    void print()
    {
        dNode *it = fir;
        while (it != NULL)
        {
            cout << it->data << " ";
            it = it->next;
        }
        cout << endl;
    }

    int size()
    {
        return count;
    }
};
