#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), mxl(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 找出 最左边的 第一个比他大的 index
    // 存入 mxl[]
    stack<pair<int, int>> stm;
    for (int i = n; i >= 1; i--)
    {
        while (stm.size() && stm.top().first < a[i])
        {
            mxl[stm.top().second] = i;
            stm.pop();
        }
        stm.push({a[i], i});
    }

    i64 ans = 0;
    stack<pair<int, vector<int>>> st;
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && a[i] > st.top().first)
        {
            int &ind = st.top().second.front();
            vector<int> &v = st.top().second;

            if (v.size() >= k)
            {
                for (int l = 0, r = k - 1; r < v.size(); l++, r++)
                {
                    if (l == 0)
                        ans += 1LL * (v[l] - mxl[ind]) * (i - v[r]);
                    else 
                        ans += 1LL * (v[l] - v[l - 1]) * (i - v[r]);
                }
            }
            st.pop();
        }
        if (st.size() && st.top().first == a[i])
        {
            st.top().second.push_back(i);
        }
        else
        {
            st.push({a[i], {i}});
        }
    }
    while (st.size())
    {
        int i = n + 1;
        int &ind = st.top().second.front();
        vector<int> &v = st.top().second;

        if (v.size() >= k)
        {
            for (int l = 0, r = k - 1; r < v.size(); l++, r++)
            {
                if (l == 0)
                    ans += 1LL * (v[l] - mxl[ind]) * (i - v[r]);
                else 
                    ans += 1LL * (v[l] - v[l - 1]) * (i - v[r]);
            }
        }
        st.pop();
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