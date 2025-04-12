#include <bits/stdc++.h>
using i64 = __int128;
using namespace std;

istream &operator>>(istream &it, __int128_t &j)
{
    string val;
    it >> val;
    reverse(val.begin(), val.end());
    __int128_t ans = 0;
    bool f = 0;
    char c = val.back();
    val.pop_back();
    for (; c < '0' || c > '9'; c = val.back(), val.pop_back())
    {
        if (c == '-')
            f = 1;
        if (val.empty())
            break;
    }
    for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back())
    {
        ans = ans * 10 + c - '0';
        if (val.empty())
            break;
    }
    j = f ? -ans : ans;
    return it;
}

ostream &operator<<(ostream &os, const __int128_t &j)
{
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x)
    {
        if (x < 0)
            ans += '-', x = -x;
        if (x > 9)
            write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}

void solve()
{
    i64 n, k;
    cin >> n >> k;
    if (k % 2)
    {
        cout << 0 << '\n';
        return;
    }

    i64 c = n / k;
    i64 ans = 0;
    if (n % k > k / 2)
    {
        ans += c * (c + 1) * (k - (n % k));
        ans += (c + 1) * (c + 1) * ((n % k) - k / 2);

        // ans += (c * (c + 1) / 2) * (k - (n % k)) + (k - (n % k)) * c;
        // ans += ((c + 1) * (c + 2) / 2) * ((n % k) - k / 2);

        // ans += (k - (n % k)) * c * (k - (n % k)) * (c + 1);
        // ans += ((n % k) - k / 2) * (c + 1) * ((n % k) - k / 2) * (c + 1);
    }
    else
    {
        ans += c * c * (k / 2 - (n % k));
        ans += c * (c + 1) * (n % k);

        // ans += (c * (c + 1) / 2) * (k / 2 - (n % k));
        // ans += (c * (c + 1) / 2) * (n % k) + (n % k) * c;

        // ans += (k / 2 - (n % k)) * c * (k / 2 - (n % k)) * c;
        // ans += (n % k) * (c + 1) * (n % k) * c;
    }
    cout << ans << '\n';
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