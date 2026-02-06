#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr, int l, int r)
{
    int pivot = l;

    int slow = l;

    for (int fast = slow + 1; fast <= r; fast++)
    {
        if (arr[fast] < arr[pivot])
        {
            slow++;
            swap(arr[slow], arr[fast]);
        }
    }

    swap(arr[slow], arr[pivot]);

    return slow;
}

void quickSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    return;

    int pivot = findPivot(arr, l, r);
    
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    cout << arr[i];
}