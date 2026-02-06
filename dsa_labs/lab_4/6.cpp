#include<bits/stdc++.h>
using namespace std;

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;

void merge(int c[], int a[], int n, int b[], int m, int f = 0, int s = 0, int ind = 0)
{
    count4++;

    if (f >= n && s >= m)
        return;

    else if (f >= n)
    {
        c[ind] = b[s];
        merge(c, a, n, b, m, f, s + 1, ind + 1);
    }

    else if (s >= m)
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

void merging(int a[], int n, int l, int mid, int r)
{
    int siz1 = mid - l + 1;
    int siz2 = r - mid;

    int c[200005];
    int left[siz1], right[siz2];

    for (int i = 0; i < siz1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < siz2; i++)
        right[i] = a[mid + 1 + i];

    merge(c, left, siz1, right, siz2);
    for (int i = 0; i < siz1 + siz2; i++)
        a[l + i] = c[i];
}

void mergesort(int a[], int n, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    mergesort(a, n, l, mid);
    mergesort(a, n, mid + 1, r);
    merging(a, n, l, mid, r);
}

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
        {
            count5++;
            small++;
        }

        while(big >= f && a[big] > a[pivot])
        {
            count5++;
            big--;
        }

        if (small >= big)
        {
            count5++;
            break;
        }

        count5++;
        swap(a[small], a[big]);
    }

    count5++;
    swap(a[pivot], a[big]);
    int curpivot = big;

    quicksort(a, n, f, curpivot - 1);
    quicksort(a, n, curpivot + 1, s);
}

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count1++;
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void selectionsort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int ch = i;
        for (int j = i + 1; j < n; j++)
        {
            count3++;
            if (a[j] < a[ch])
            {
                ch = j;
            }
        }

        if (i != ch)
        {
            count3++;
            swap(a[i], a[ch]);
        }
    }
}

void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j])
        {
            count2++;
            a[j + 1] = a[j]; 
            j--;
        }

        count2++;
        a[j + 1] = key;
    }
}

int main()
{
    for (int q = 3; q > 0; q--)
    {
        int n;
        
        if (q == 3)
        n = 10;

        else if (q == 2)
        n = 100;

        else if (q == 1)
        n = 1000;

        int a[n];

        srand(time(0));

        for (int i = 0; i < n; i++)
        {
            a[i] = rand();
        }

        int bub[n], ins[n], sel[n], mer[n], qck[n];

        for (int i = 0; i < n; i++)
        {
            bub[i] = ins[i] = sel[i] = mer[i] = qck[i] = a[i];
        }

        bubblesort(bub, n);
        insertionsort(ins, n);
        selectionsort(sel, n);
        mergesort(mer, n, 0, n - 1);
        quicksort(qck, n, 0, n - 1);

        cout << "PERFORMANCE WHEN " << n << " RANDOM NUMBERS:" << endl << endl;

        if (n == 1000)
        {
            for (int i = 0; i < n; i++)
            cout << bub[i] << " ";
            cout << endl << endl;

            cout << "Bubble Sort Comparsion: " << count1 << endl;
            cout << "Insertion Sort Comparsion: " << count2 << endl;
            cout << "Selection Sort Comparsion: " << count3 << endl;
            cout << "Merge Sort Comparsion: " << count4 << endl;
            cout << "Quick Sort Comparsion: " << count5 << endl;
        }
        
        else
        {
            cout << "Bubble Sort Comparsion: " << count1 << endl;
            for (int i = 0; i < n; i++)
            cout << bub[i] << " ";
            cout << endl << endl;

            cout << "Insertion Sort Comparsion: " << count2 << endl;
            for (int i = 0; i < n; i++)
            cout << ins[i] << " ";
            cout << endl << endl;;

            cout << "Selection Sort Comparsion: " << count3 << endl;
            for (int i = 0; i < n; i++)
            cout << sel[i] << " ";
            cout << endl << endl;;

            cout << "Merge Sort Comparsion: " << count4 << endl;
            for (int i = 0; i < n; i++)
            cout << mer[i] << " ";
            cout << endl << endl;;

            cout << "Quick Sort Comparsion: " << count5 << endl;
            for (int i = 0; i < n; i++)
            cout << qck[i] << " ";
            cout << endl << endl;;
        }

        cout << endl;

        count1 = count2 = count3 = count4 = count5 = 0;
    }
}
