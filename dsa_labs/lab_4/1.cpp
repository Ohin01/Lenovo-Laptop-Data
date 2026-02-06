#include<bits/stdc++.h>
using namespace std;

int lower_bound(int a[], int n, int x)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (x <= a[mid])
        right = mid;

        else
        left = mid + 1;
    }

    return left == n? -1:left;
}

int last_occur(int a[], int n, int x)
{
    int left = 0;
    int right = n;

    int match = -1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (x < a[mid])
        right = mid;

        else if (x == a[mid])
        {
            match = mid;
            left = mid + 1;
        }

        else
        left = mid + 1;
    }

    return match;
}

int main()
{
    int a[200005];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    cin >> a[i];

    int x;
    cin >> x;

    if (lower_bound(a, n, x) == -1)
    {
        cout << "Not present in the array" << endl;
        return 0;
    }

    cout << "First Index: " << lower_bound(a, n, x) + 1 << endl;
    cout << "Last Index: " << last_occur(a, n, x) + 1 << endl;
    cout << "Count: " << last_occur(a, n, x) - lower_bound(a, n, x) + 1 << endl;

    return 0;
}