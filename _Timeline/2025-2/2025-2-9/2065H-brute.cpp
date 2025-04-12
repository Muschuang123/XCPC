#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;

    string ss = " ";
    function<void (int)> dfs = [&](int i) -> void
    {
        if (i == n + 1)
        {
            for (int i = 1; i < ss.size(); i++)
            {
                ans += ss[i] != ss[i - 1];
            }
            return;
        }
        ss.push_back(s[i]);
        dfs(i + 1);
        ss.pop_back();
        dfs(i + 1);
    };

    dfs(1);

    cout << ans << '\n';    

    return 0;
}