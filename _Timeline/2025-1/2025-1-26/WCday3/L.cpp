#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    n++;
    int a[10][10] = {0};
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = ++cnt;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i][1] << ' ';
    }
    
    for (int i = n; i >= 2; i--)
    {
        for (int j = 2; j <= i - 1; j++)
        {
            cout << a[i][j] << ' ';
        }
        for (int j = i; j >= 1;)
        {
            cout << a[i][j] << ' ' << flush;
            j--;
            if (j < 1)
                break;
            cout << a[i - 1][j] << ' ' << flush;
            if (j == 1)
                break;
        }
    }

    return 0;
}