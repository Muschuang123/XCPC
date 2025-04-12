#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, TTTTT;
    cin >> n >> TTTTT;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) a[i] = b[i] - a[i];

    // 最临近的先吃
    stack<int> st;
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            st.push(i);
        }
        else
        {
            while (st.size() && a[i] > 0)
            {
                int x = st.top();
                st.pop();
                int de = min(-a[x], a[i]);
                a[x] += de;
                a[i] -= de;
                if (a[x] < 0)   
                {
                    st.push(x);
                }
                else 
                {
                    res[x] = i;
                }
            }
            res[i] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            st.push(i);
        }
        else
        {
            while (st.size() && a[i] > 0)
            {
                int x = st.top();
                st.pop();
                int de = min(-a[x], a[i]);
                a[x] += de;
                a[i] -= de;
                if (a[x] < 0)   
                {
                    st.push(x);
                }
                else 
                {
                    if (res[x] == 0)
                        res[x] = i;
                }
            }
            if (res[i] == 0)
                res[i] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res[i] < i)
            res[i] += n;
        ans = max(ans, res[i] - i);
    }
    cout << ans + 1 << '\n';
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