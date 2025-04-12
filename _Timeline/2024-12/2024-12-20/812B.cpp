#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<string> a;
vector<int> st;
vector<int> en;
int ans = 0x3f3f3f3f;

void dfs(int i, int res, int w)
{
    if (i == 1)
    {
        ans = min(ans, res);
        return;
    }
    if (st[i - 1] == 0)
    {
        int ok = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (st[j] != 0)
                ok = 0;
        }
        if (ok)
        {
            ans = min(ans, res);
            return;
        }
        dfs(i - 1, res + 1, w);
    }
    else
    {
        dfs(i - 1, res + w + en[i - 1] + 1, en[i - 1]);
        dfs(i - 1, res + m + 1 - w + m + 2 - st[i - 1], st[i - 1]);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1);
    st.resize(n + 1);
    en.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int fl = 0;
        for (int j = 1; j <= m; j++)
        {
            if (!fl && a[i][j] == '1')
            {
                st[i] = j;
                fl = 1;
            }
            if (a[i][j] == '1')
                en[i] = j;
        }
    }
    dfs(n, en[n], en[n]);
    cout << ans;

    return 0;
}