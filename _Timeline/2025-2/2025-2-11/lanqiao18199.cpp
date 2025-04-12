// https://www.lanqiao.cn/problems/18199/learning/?page=1&first_category_id=1&problem_id=18199
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + ksm(26, (n - i)) * ('z' - s[i])) % mod;
    }

    cout << ans << '\n';

    return 0;
}