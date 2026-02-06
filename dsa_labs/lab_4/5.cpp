#include<bits/stdc++.h>
using namespace std;

void quicksort(int a[], int n, int f, int s)
{
    if (f >= s)
    return;

    int small = f + 1;
    int big = s;

    int pivot = f;

    while (true)
    {
        while (small <= s && a[small] <= a[pivot])
        small++;

        while(big >= f && a[big] > a[pivot])
        big--;

        if (small >= big)
        break;

        swap(a[small], a[big]);
    }

    swap(a[pivot], a[big]);
    int curpivot = big;

    quicksort(a, n, f, curpivot - 1);
    quicksort(a, n, curpivot + 1, s);
}

int main()
{
    int n;
    cin >> n;
    
    int a[n];

    for (int i = 0; i < n; i++)
    cin >> a[i];

    quicksort(a, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;

    return 0;
}