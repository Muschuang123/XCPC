#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    stringstream ss;
    string s;
    getline(cin, s);
    ss << s;
    int x;
    vector<int> a;
    while (ss >> x)
    {
        a.push_back(x);
    }
    int odd = 0, even = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (i & 1)
            odd ^= a[i];
        else 
            even ^= a[i];
    }

    if (odd == even)
    {
        cout << "Accepted" << '\n';
    }
    else
    {
        cout << "Wrong Answer" << '\n';
    }
    
    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    string s;
    getline(cin, s);
    while (tt--)
        solve();
    return 0;
}