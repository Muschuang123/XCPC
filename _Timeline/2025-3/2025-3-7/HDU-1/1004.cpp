#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

struct SparseTable
{
    int maxx[maxn][25], lg[maxn];
    int n, a[maxn];
 
    void build()
    {
        lg[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            maxx[i][0] = a[i];
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 1; i <= lg[n]; i++)
        {
            for (int j = 1; j + (1 << i) - 1 <= n; j++)
            {
                maxx[j][i] = max(maxx[j][i - 1], maxx[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
 
    int query(int l, int r)
    {
        int len = lg[r - l + 1];
        return max(maxx[l][len], maxx[r - (1 << len) + 1][len]);
    }
} ST;

void solve()
{
    int n, q;
    cin >> n >> q;
    ST.n = n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> le(n + 1), re(n + 1);
    multiset<int> ss[2];
    for (int l = 1, r = 1; r <= n + 1; r++)
    {
        if (r > n)
        {
            while (l < r)
            {
                re[l] = r - 1;
                l++;
            }
            break;
        }
        ss[r % 2].insert(a[r]);
        while (ss[0].size() && ss[1].size() && 
            *ss[0].begin() <= *ss[1].rbegin() &&
            *ss[1].begin() <= *ss[0].rbegin())
        {
            ss[l % 2].extract(a[l]);
            re[l] = r - 1;
            l++;
        }
        le[r] = l;
    }

    for (int i = 1; i <= n; i++)
    {
        ST.a[i] = re[i] - i + 1;
    }
    ST.build();

    i64 ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (re[l] >= r || le[r] <= l)
        {
            int res = r - l + 1;
            // cout << res << '\n';
            ans = (ans + 1LL * res * i) % mod;
            continue;
        }

        int pos = --upper_bound(re.begin() + 1, re.end(), r) - re.begin();

        int res = 0;
        if (pos < n)
            res = max(res, r - (pos + 1) + 1);
        if (pos >= l)
            res = max(res, ST.query(l, pos));
        // cout << res << '\n';
        ans = (ans + 1LL * res * i) % mod;
    }
    cout << ans << '\n';
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