#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> fir;
    vector<int> sec;

    for (int i = l; i <= mid; i++)
    fir.push_back(arr[i]);

    for (int i = mid + 1; i <= r; i++)
    sec.push_back(arr[i]);

    int p1 = 0, p2 = 0;
    vector<int> ans;

    while (p1 < fir.size() && p2 < sec.size())
    {
        if (fir[p1] <= sec[p2])
        {
            ans.push_back(fir[p1]);
            p1++;
        }

        else
        {
            ans.push_back(sec[p2]);
            p2++;
        }
    }

    while (p1 != fir.size())
    {
        ans.push_back(fir[p1]);
        p1++;
    }

    while (p2 != sec.size())
    {
        ans.push_back(sec[p2]);
        p2++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        arr[i + l] = ans[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    mergeSort(arr, 0, n - 1);
}