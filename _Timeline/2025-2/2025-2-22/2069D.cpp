#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    string a;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != s[n - i + 1])
        {
            for (int j = i; j <= n - i + 1; j++)
            {
                a.push_back(s[j]);
            }
            break;
        }
    }

    n = a.size();
    a = " " + a;
    
    auto check = [&](int mid)
    {
        vector<int> t(26);
        // 打乱
        for (int i = 1; i <= mid; i++)
        {
            t[a[i] - 'a']++;
        }
        // 如果没有打乱到一半，验证一下 不能操作的部分是不是已经对齐
        for (int i = mid + 1; i <= n / 2; i++)
        {
            if (a[i] != a[n - i + 1])
                return 0;
        }
        // 按照打乱的内容 能不能 对齐
        for (int i = max(mid + 1, n - mid + 1); i <= n; i++)
        {
            if (t[a[i] - 'a'] == 0)
                return 0;
            t[a[i] - 'a']--;
        }
        // 如果打乱的部分 长度 大于 没打乱的，看看剩下的能不能 对齐
        // for (int i = 0; i < 26; i++)
        // {
        //     if (t[i] % 2)
        //         return 0;
        // }
        // 哈哈哈其实不用验证的，
        // 因为如果前面都能对齐，按照题目输入限制，自动可以对齐
        return 1;
    };
    
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }

    int ans = r;

    reverse(a.begin() + 1, a.end());
    l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << min(ans, r) << '\n';
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