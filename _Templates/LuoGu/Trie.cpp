#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int maxn = 3e6 + 6;

const int sz = 62;
int ch[maxn][sz], cnt[maxn];
int idx = 0;

void Tinsert(const string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int v = 0;
        if (s[i] >= 'a' && s[i] <= 'z')
            v = s[i] - 'a';
        if (s[i] >= 'A' && s[i] <= 'Z')
            v = s[i] - 'A' + 26;
        if (s[i] >= '0' && s[i] <= '9')
            v = s[i] - '0' + 52;
        if (!ch[u][v])
            ch[u][v] = ++idx;
        u = ch[u][v];
        cnt[u]++;
    }
}

// return the number of strings in Trie.
int Tquery(const string &s)
{
    int res = 0;
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int v = 0;
        if (s[i] >= 'a' && s[i] <= 'z')
            v = s[i] - 'a';
        if (s[i] >= 'A' && s[i] <= 'Z')
            v = s[i] - 'A' + 26;
        if (s[i] >= '0' && s[i] <= '9')
            v = s[i] - '0' + 52;
        if (!ch[u][v])
            return 0;
        u = ch[u][v];
    }
    return cnt[u];
}

void Tclear()
{
    for (int i = 0; i <= idx; i++)
    {
        cnt[i] = 0;
        for (int j = 0; j < sz; j++)
            ch[i][j] = 0;
    }
    idx = 0;
}

void solve()
{
    Tclear();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        Tinsert(s);
    }
    while (q--)
    {
        string s;
        cin >> s;
        cout << Tquery(s) << '\n';
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