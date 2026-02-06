#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 1 || n == 0) return 1;
    else return n * fact(n - 1);
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << "Factorial: " << fact(n) << endl;

    cout << "Fibonacci: ";
    
    for (int i = 1; i <= n; i++)
    cout << fibonacci(i) << " ";
    cout << endl;
    return 0;
}