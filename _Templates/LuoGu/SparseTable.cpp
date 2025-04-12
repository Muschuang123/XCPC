// https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

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
} st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m;
    cin >> st.n >> m;
    for (int i = 1; i <= st.n; i++) cin >> st.a[i];
    st.build();
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }

    return 0;
}