#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    if n is odd: 
        let x is the number of odd number from 1 to n.
        if x is odd, do [0, 2, 3, 4, 5, ....]
        if x is even, do [1, 2, 3, 4, 5, ....]
            so that we can do the last bit of 1 is equal, and other equal.
    
    if n is even: 
        we just put 0 as the a[n]. 
        and others as same as odd case, but << 1 for all number. 
        to avoid another 0 appear, we just let 0 = 2, 
            and another arbitrary number + 2.
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    if (n & 1)
    {
        int res = n - 1;
        res /= 2;
        a[1] = res & 1;
        for (int i = 2; i <= n; i++)
        {
            a[i] = i;
        }
    }
    else
    {
        a[n] = 0;
        int res = n - 2;
        res /= 2;
        a[1] = res & 1;
        for (int i = 2; i <= n - 1; i++)
        {
            a[i] = i;
        }

        for (int i = 1; i <= n - 2; i++)
        {
            a[i] <<= 1;
            a[i] |= 1;
        }
        a[n - 1] <<= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}