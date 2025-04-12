#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    sort(b.begin() + 1, b.end(), greater<>());
    for (int i = 1; i <= m; i++)
    {
        vector<int> st;
        st.push_back(b[i]);
        while (st.size())
        {
            int x = st.back();
            st.pop_back();
            if (x == 0)
            {
                cout << "No\n";
                return;
            }
            if (a.count(x))
            {
                a.extract(x);
            }
            else
            {
                st.push_back((x + 1) / 2);
                st.push_back(x / 2);
            }
        }
    }
    if (a.size())
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
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