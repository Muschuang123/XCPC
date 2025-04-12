#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<char> op(2 * n + 1);
    vector<int> num(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> op[i];
        if (op[i] == '-')
        {
            cin >> num[i];
        }
    }

    vector<pair<int, int>> st;
    vector<vector<int>> ans(n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (op[i] == '-')
        {
            while (st.size() && st.back().first < num[i] && st.back().second == 0)
            {
                st.pop_back();
            }
            if (st.empty() || st.back().first > num[i] && st.back().second == 0)
            {
                cout << "NO";
                return 0;
            }
            st.back().second--;
            ans[st.back().first].push_back(num[i]);
            st.push_back({num[i], 0});
        }
        else
        {
            if (st.size())
            {
                st.back().second++;
            }
            else
            {
                st.push_back({0, 1});
            }
        }
    }

    cout << "YES\n";
    vector<int> s;
    s.push_back(0);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (op[i] == '+')
        {
            cout << ans[s.back()].back() << ' ';
            ans[s.back()].pop_back();
            if (ans[s.back()].empty())
                s.pop_back();
        }
        else
        {
            s.push_back(num[i]);
        }
    }

    return 0;
}