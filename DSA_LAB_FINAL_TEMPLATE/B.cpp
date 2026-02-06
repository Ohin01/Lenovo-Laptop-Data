#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
struct max_heap 
{
    vector<T> arr;
    int sz;

    max_heap(int n) 
    {
        arr.resize(n + 1);
        sz = 0;
    }

    void heapify(int node) 
    {
        int left = node * 2;
        int right = node * 2 + 1;
        int smaller = node;

        if (left <= sz && arr[left] > arr[smaller])
            smaller = left;
        if (right <= sz && arr[right] > arr[smaller])
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

        while (cur > 1 && arr[cur] > arr[cur / 2]) 
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


    bool empty() {
        return sz == 0;
    }
};

int main() 
{
    ll n, k;
    cin >> n >> k;

    max_heap<ll> mx(n);

    vector<ll> ans;

    for (ll i = 0; i < n; i++) 
    {
        ll num;
        cin >> num;

        mx.insert(num);

        ll f = mx.top();
        mx.pop();
        mx.insert(f - k);
    }

    while (!mx.empty())
    {
        ans.push_back(mx.top());
        mx.pop();
    }

    for (int i = n - 1; i >= 1; i--)
    cout << ans[i] << " ";

    cout << ans[0];
    cout << endl;
    return 0;
}
