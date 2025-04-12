#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> sum;
    string dic = "abc";
    for (char a : dic)
    {
        for (char b : dic)
        {
            for (char c : dic)
            {
                if (a != b && b != c && a != c)
                {
                    sum.push_back(vector<int>(n + 1));
                    for (int i = 1; i <= n; i++)
                    {
                        string tmp = {a, b, c};
                        char d = tmp[i % 3];
                        sum.back()[i] = sum.back()[i - 1] + (s[i] != d);
                    }
                }
            }
        }
    }
    
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 1e18 + 9;
        for (auto &v : sum)
        {
            ans = min(ans, v[r] - v[l - 1]);
        }
        cout << ans << '\n';
    }
    


    return 0;
}