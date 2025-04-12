#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        s.push_back(s[i]);
    
    string mn(n, 'z');
    int mni = 0;
    for (int i = 0; i < n; i++)
    {
        if ((n - i) % 2 == 0 && (s.substr(i, n) < mn || s.substr(i, n) == mn && i < mni))
        {
            mn = s.substr(i, n);
            mni = i;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        reverse(s.begin() + n, s.begin() + n + i);
        if ((n - i) % 2 == 1 && (s.substr(i, n) < mn || s.substr(i, n) == mn && i < mni))
        {
            mn = s.substr(i, n);
            mni = i;
        }
        reverse(s.begin() + n, s.begin() + n + i);
    }


    cout << mn << '\n';
    cout << mni + 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}