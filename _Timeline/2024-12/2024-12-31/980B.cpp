#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    e.g. input is 7 7: 
    .......
    .#.##..
    .####..
    .......

    the other solution is puts all '#' from two sides to mid.
    and if the k is odd, just put 1 in the middle.
    critical information: n is odd. thats why it works.
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<char>> a(5, vector<char>(n + 1, '.'));

    if (k == 1 || k == 3)
    {
        if (k == 1)
        {
            a[2][n / 2 + 1] = '#';
        }
        else
        {
            a[2][n / 2] = a[2][n / 2 + 1] = a[2][n / 2 + 2] = '#';
        }
        
    }
    else if (k % 2 == 0)
    {
        for (int i = 2; i <= k / 2 + 1; i++)
        {
            a[2][i] = a[3][i] = '#';
        }
    }
    else
    {
        for (int i = 2; i <= (k + 1) / 2 + 1; i++)
        {
            a[2][i] = a[3][i] = '#';
        }
        a[2][3] = '.';
    }
    
    cout << "YES\n";
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
        }
        cout << '\n';
    }
    

    return 0;
}