#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n + 1), v(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> v[i];
    }

    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        while (st.size() && st.top().second <= h[i])
        {
            st.pop();
        }
        if (st.size())
        {
            a[st.top().first] += v[i];
        }
        st.push({i, h[i]});
    }

    while (st.size())
    {
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        while (st.size() && st.top().second <= h[i])
        {
            st.pop();
        }
        if (st.size())
        {
            a[st.top().first] += v[i];
        }
        st.push({i, h[i]});
    }

    cout << *max_element(a.begin() + 1, a.end());

    return 0;
}