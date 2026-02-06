#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1005, vector<int>(1005, 0));

void solve()
{
    int n, m;
    cin >> n >> m;

    //vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        cin >> a[i][j];
    }

    int x = 0;
    int y = 0;

    int dx = -1;
    int dy = 1;

    cout << a[x][y] << " ";

    while (true)
    {
        if (x == n - 1 && y == m - 1)
        break;

        if (x + dx < 0 || x + dx > n - 1 || y + dy < 0 || y + dy > m - 1)
        {
            if (dx == -1)
            {
                if (y + dy < 0 || y + dy > m - 1)
                {
                    x++;
                }

                else
                {
                    y++;
                }
            }

            else
            {
                if (x + dx < 0 || x + dx > n - 1)
                {
                    y++;
                }

                else
                {
                    x++;
                }
            }

            cout << a[x][y] << " ";

            dx *= (-1);
            dy *= (-1);
        }

        else
        {
            x += dx;
            y += dy;

            cout << a[x][y] << " ";
        }
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    solve();
}