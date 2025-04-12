#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> b(26);
    for (auto &c : s)
        b[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (b[i] == n)
        {
            cout << "NO\n";
            return;
        }
    }
    string t = s;
    reverse(t.begin(), t.end());
    if (t <= s && k == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

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