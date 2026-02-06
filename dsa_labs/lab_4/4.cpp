#include<bits/stdc++.h>
using namespace std;

void merge(int c[], int a[], int n, int b[], int m, int f = 0, int s = 0, int ind = 0)
{
    if (f >= n && s >= m)
    {
        return;
    }

    else if (f >= n)
    {
        c[ind] = b[s];
        merge(c, a, n, b, m, f, s + 1, ind + 1);
    }

    else if (s >= m )
    {
        c[ind] = a[f];
        merge(c, a, n, b, m, f + 1, s, ind + 1);
    }

    else
    {
        if (a[f] <= b[s])
        {
            c[ind] = a[f];
            merge(c, a, n, b, m, f + 1, s, ind + 1);
        }

        else
        {
            c[ind] = b[s];
            merge(c, a, n, b, m, f, s + 1, ind + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n + 1];

    for (int i = 0; i < n; i++)
    cin >> a[i];

    int m;
    cin >> m;

    int b[n + 1];

    for (int i = 0; i < m; i++)
    cin >> b[i];

    int c[n + m + 1];

    int ind = 0;

    merge(c, a, n, b, m);

    for (int i = 0; i < n + m; i++)
    cout << c[i] << " ";
    cout << endl;

    return 0;
}