#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define endl '\n'
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;

int v[6];

struct Trie
{
    int ch[maxn][32], cnt[maxn];
    int idx = 0;

    void insert(const string &s, const int &x)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int v = s[i] - 'a';
            if (!ch[u][v])
                ch[u][v] = ++idx;
            u = ch[u][v];
        }
        if (cnt[u] == 0)
            cnt[u] = x;
        else
            cnt[u] = min(cnt[u], x);
    }

    int query(const string &s)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int v = s[i] - 'a';
            if (!ch[u][v])
                return inf;
            u = ch[u][v];
        }
        return (cnt[u] == 0 ? inf : cnt[u]);
    }
} t[32];

// gp_hash_table<ll, int> pos; // 标准写法

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            int x;
            cin >> s >> x;
            int len = s.size();
            for (int i = 0; i < (1 << len); i++)
            {
                string p = "";
                for (int j = 0; j <= len - 1; j++)
                {
                    if ((i >> j) & 1)
                    {
                        p += s[j];
                    }
                }
                t[i].insert(p, x);
            }
        }
        else
        {
            string s;
            cin >> s;
            memset(v, inf, sizeof(v));
            int len = s.size();
            for (int i = 0; i < (1 << len); i++)
            {
                string p = "";
                int cnt = 0;
                for (int j = 0; j <= len - 1; j++)
                {
                    if ((i >> j) & 1)
                    {
                        cnt++;
                        p += s[j];
                    }
                }
                // cout << i << ' ' << p << ' ' << t[i].query(p) << endl;
                v[cnt] = min(v[cnt], t[i].query(p));
            }

            int ans = 0;
            for (int i = 5; i >= 0; i--)
            {
                if (v[i] != inf)
                {
                    ans = v[i];
                    break;
                }
            }
            // cout << v[1] << endl;
            cout << ans << endl;
        }
    }
}