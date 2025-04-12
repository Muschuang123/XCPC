#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;
const int maxn = 1e6 + 6;

i64 f[maxn], g[maxn];
i64 ksm(i64 a, i64 n) {
    i64 ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void init() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

i64 C(i64 n, i64 m) {
    if (m > n || n < 0 || m < 0) {
        return 0;
    }
    if (m == 0) {
        return 1;
    }
    return f[n] * g[m] % mod * g[n - m] % mod;
}

int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<i64> vec;
    i64 cur = 0;
    for (int i = 1; i <= n; i++)
    {
        // 1
        if (i < n && s[i] == '(' && s[i + 1] == ')')
        {
            cur++;
            i++;
        }
        else if (s[i] == ')')
        {
            cur++;
            vec.push_back(cur);
            cur = 0;
        }
    } 
    vec.push_back(cur);

    for (int i = (int)vec.size() - 2; i >= 0; i--)
    {
        vec[i] = (vec[i] + vec[i + 1]) % mod;
    }

    i64 ans = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        ans = ans * C(vec[i] + 1, 1) % mod;
    }
    cout << ans << '\n';

    return 0;
}