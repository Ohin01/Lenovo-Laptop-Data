#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct OhinStack
{
    vector<T> arr;
    int cur;

    OhinStack(int n)
    {
        arr.resize(n);
        cur = -1;
    }

    void push(T num)
    {
        if (cur == arr.size() - 1)
        {
            cout << "Stack is FULL" << endl;
            return;
        }

        cur++;
        arr[cur] = num;
    }

    void pop()
    {
        if (cur == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        cur--;
    }

    T top()
    {
        if (cur == -1) return -1;

        return arr[cur];
    }

    bool isEmpty()
    {
        if (cur == -1) return true;
        else return false;
    }

    int size()
    {
        return top + 1;
    }

    void print()
    {
        for (int i = 0; i <= cur; i++)
        cout << arr[i] << endl;
    }
};

int main(void)
{
    OhinStack<int> st(10);

    st.push(1);
    st.push(2);

    st.print();
}
