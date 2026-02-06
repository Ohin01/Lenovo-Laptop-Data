#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct OhinQueue
{
    vector<T> arr;
    int cur;
    int cap;
    int sz;
    int rear;

    OhinQueue(int n)
    {
        arr.resize(n);
        cur = 0;
        sz = 0;
        cap = n;
        rear = 0;
    }

    void push(T num)
    {
        if (sz == arr.size())
        {
            cout << "Queue is FULL" << endl;
            return;
        }

        arr[rear] = num;
        rear++;
        sz++;
        rear %= cap;
    }

    void pop()
    {
        if (sz == 0)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cur++;
        cur %= cap;
        sz--;
    }

    T front()
    {
        if (sz == 0) return -1;

        return arr[cur];
    }

    bool isEmpty()
    {
        if (sz == 0) return true;
        else return false;
    }

    void print()
    {
        for (int i = 0; i < sz; i++)
        cout << arr[(cur + i) % cap] << endl;
    }

    int size()
    {
        return sz;
    }
};

int main(void)
{

}
