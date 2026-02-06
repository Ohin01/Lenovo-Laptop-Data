#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct min_heap 
{
    vector<T> arr;
    int sz;

    min_heap(int n) 
    {
        arr.resize(n + 1);
        sz = 0;
    }

    void heapify(int node) 
    {
        int left = node * 2;
        int right = node * 2 + 1;
        int smaller = node;

        if (left <= sz && arr[left] < arr[smaller])
            smaller = left;
        if (right <= sz && arr[right] < arr[smaller])
            smaller = right;

        if (smaller != node)
        {
            swap(arr[node], arr[smaller]);
            heapify(smaller);
        }
    }

    void insert(T val) 
    {
        sz++;
        arr[sz] = val;
        int cur = sz;

        while (cur > 1 && arr[cur] < arr[cur / 2]) 
        {
            swap(arr[cur], arr[cur / 2]);
            cur /= 2;
        }
    }

    T top() 
    {
        if (sz >= 1)
            return arr[1];
        
            return -1;
    }

    void pop() 
    {
        if (sz < 1) return;

        swap(arr[1], arr[sz]);
        sz--;
        heapify(1);
    }

    void deleteIndex(int ind)
    {
        if (ind > sz) return;

        swap(arr[ind], arr[sz]);
        sz--;

        if (ind > 1 && arr[ind / 2] < arr[ind])
        {
            while (ind > 1 && arr[ind / 2] < arr[ind])
            {
                swap(arr[ind / 2], arr[ind]);
                ind /= 2;
            }
        }

        else 
        {
            heapify(ind);
        }  
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    int n;
    cin >> n;

    min_heap<int> mn(n);

    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;
        mn.insert(num);
    }

    while (!mn.empty()) 
    {
        cout << mn.top() << " ";
        mn.pop();
    }

    cout << endl;
    return 0;
}
