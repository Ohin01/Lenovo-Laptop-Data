#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int find)
{
    int lo = 0;
    int hi = arr.size() - 1;

    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (find < arr[mid])
        {
            hi = mid - 1;
        }

        else if (find > arr[mid])
        {
            lo = mid + 1;
        }

        else
        {
            ans = mid;
            break;
        }
    }

    return ans;
}

bool isEven(int n)
{
    if (n % 2 == 0) return true;
    else return false;
}

int binarySearchOnAns(vector<int> &arr, int find)
{
    int lo = 0;
    int hi = arr[arr.size() - 1];

    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (isEven(mid))
        {
            ans = mid;
            lo = mid + 1;
        }

        else
        {
            hi = mid - 1;
        }
    }

    return ans;
}

int lowerBound(vector<int> &arr, int find)
{
    int lo = 0;
    int hi = arr.size();

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (find <= arr[mid])
        {
            hi = mid;
        }

        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

int upperBound(vector<int> &arr, int find)
{
    int lo = 0;
    int hi = arr.size();

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (find < arr[mid])
        {
            hi = mid;
        }

        else
        {
            lo = mid + 1;
        }
    }

    return lo;
}

int main(void)
{
    
}