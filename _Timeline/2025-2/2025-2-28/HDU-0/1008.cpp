#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << mp["Au"] + min(mp["Ag"], mp["Cu"]) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}