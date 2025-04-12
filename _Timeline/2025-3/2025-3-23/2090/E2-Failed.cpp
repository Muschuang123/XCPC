#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) a[i] = b[i] - a[i];

    auto check = [&](int mid)
    {
        vector<int> ca = a;
        i64 need = 0;
        vector<int> st;
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
            {
                st.push_back(i);
            }
            else
            {
                while (st.size() && a[i] >= 0)
                {
                    int x = st.back();
                    int de = min(-a[x], a[i]);
                    a[x] += de;
                    a[i] -= de;
                    if (a[x] < 0)   
                    {
                        if (i - st.front() > mid)
                        {
                            need -= a[x];
                            a[x] = 0;
                        }
                        else
                        {
                            st.push_back(1);
                        }
                    }
                    else 
                    {
                        res[x] = i;
                    }
                    st.pop_back();
                }
                res[i] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
            {
                st.push_back(i);
            }
            else
            {
                while (st.size() && a[i] >= 0)
                {
                    int x = st.back();
                    int de = min(-a[x], a[i]);
                    a[x] += de;
                    a[i] -= de;
                    if (a[x] < 0)   
                    {
                        if (n + i - st.front() > mid)
                        {
                            need -= a[x];
                            a[x] = 0;
                        }
                        else
                        {
                            st.push_back(1);
                        }
                    }
                    else 
                    {
                        if (res[x] == 0)
                            res[x] = i;
                    }
                    st.pop_back();
                }
            }
        }
        a = ca;
        return need <= k;
    };
    int l = -1, r = n - 1; 
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << r + 1 << '\n';
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