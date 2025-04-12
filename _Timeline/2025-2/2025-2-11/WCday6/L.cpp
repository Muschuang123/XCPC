#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "CHICKEN";
    int sz = t.size();
    int p = 0;

    vector<int> a(26);
    for (int i = 0; i < n; i++)
    {
        if (p < sz && t[p] == s[i])
        {
            p++;
        }
        else
        {
            a[s[i] - 'A']++;
        }
    }
    if (p == sz && n >= sz && (n - sz) % 2 == 0 && 
        *max_element(a.begin(), a.end()) * 2 <= accumulate(a.begin(), a.end(), 0))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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