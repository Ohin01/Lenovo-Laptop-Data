#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int pr;
    int val;

    Node() {};
    
    Node(int priority, int value)
    {
        pr = priority;
        val = value;
    }
};


struct Pr_queue{
    vector<Node> arr;
    int sz;

    Pr_queue(int n) 
    {
        arr.resize(n + 1); 
        sz = 0;
    }

    void heapify(int node) 
    {
        int left = node * 2;
        int right = node * 2 + 1;
        int smaller = node;

        if (left <= sz && (arr[left].pr < arr[smaller].pr || (arr[left].pr == arr[smaller].pr && arr[left].val < arr[smaller].val)))
            smaller = left;
        if (right <= sz && (arr[right].pr < arr[smaller].pr || (arr[right].pr == arr[smaller].pr && arr[right].val < arr[smaller].val)))
            smaller = right;

        if (smaller != node) 
        {
            swap(arr[node], arr[smaller]);
            heapify(smaller);
        }
    }

    void insert(Node val)
    {
        sz++;
        arr[sz] = val;
        int cur = sz;

        while (cur > 1 && (arr[cur].pr < arr[cur / 2].pr || (arr[cur].pr == arr[cur / 2].pr && arr[cur].val < arr[cur / 2].val))) 
        {
            swap(arr[cur], arr[cur / 2]);
            cur /= 2;
        }
    }

    Node top() 
    {
        if (sz >= 1)
            return arr[1];
        
        return {-1, -1};
    }

    void pop() 
    {
        if (sz < 1) return;

        swap(arr[1], arr[sz]);
        sz--;
        heapify(1);
    }

    bool empty() 
    {
        return sz == 0;
    }
};

int main() {
    int n;
    cin >> n;

    Pr_queue mn(n);

    for (int i = 0; i < n; i++) 
    {
        int pr;
        cin  >> pr;

        int num;
        cin >> num;

        Node el(pr, num);

        mn.insert(el);
    }

    while (!mn.empty()) {
        cout << mn.top().pr << " " << mn.top().val << " ";
        cout << endl;
        mn.pop();
    }

    cout << endl;
    return 0;
}
