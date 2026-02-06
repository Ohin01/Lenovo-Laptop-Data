#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int n)
{
    if (n == 1)
    return a[n - 1];

    return a[n - 1] + sum(a, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int a[200005];

    for (int i = 0; i < n; i++)
    cin >> a[i];

    cout << sum(a, n);
    return 0;
}