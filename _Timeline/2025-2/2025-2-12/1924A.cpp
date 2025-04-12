#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 本质是上把 s 分为 >= n 段，每一段内都要出现 所有 前 k 个 字母。
 * 全出现了就刷新，记录一下来的最晚的那个字符。
 * 如果刷新 >= n 次，就可以。
 * 否则 按照每次来的最晚的字符，组成一个串，
 * 然后最后一次不是没刷新吗，看看因为谁没刷新，加进来，
 * 如果串长不够，就用 'a' 补齐。
 */

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> a(k), vec;
    for (int i = 1; i <= m; i++)
    {
        int cur = s[i] - 'a';
        a[cur] = 1;
        int res = 0;
        for (int j = 0; j < k; j++)
        {
            res += a[j];
        }
        if (res == k)
        {
            vec.push_back(i);
            a.assign(26, 0);
        }
    }
    if (vec.size() >= n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
        int need = n - vec.size();
        for (auto &i : vec)
        {
            cout << s[i];
        }
        if (vec.empty())
            vec.push_back(0);
        a.assign(26, 0);
        for (int i = vec.back() + 1; i <= m; i++)
        {
            int cur = s[i] - 'a';
            a[cur] = 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] == 0)
            {
                cout << (char)(i + 'a');
                need--;
                break;
            }
        }
        for (int i = 1; i <= need; i++)
        {
            cout << 'a';
        }
        cout << '\n';
    }
    
    
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