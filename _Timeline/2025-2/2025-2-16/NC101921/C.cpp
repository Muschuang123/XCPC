#include <bits/stdc++.h>
using i64 = __int128_t;
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
    i64 n, l, r;
    cin >> n >> l >> r;

    auto check = [&](i64 mid, i64 fi)
    {
        return mid * (mid + 1) / 2 < fi;
    };

    i64 ll = 0, rr = n;
    while (ll + 1 < rr)
    {
        i64 mid = ll + rr >> 1;
        if (check(mid, l))
            ll = mid;
        else 
            rr = mid;
    }
    i64 res = ll;
    if (check(res, r) && !check(res + 1, r) || check(res + 1, r) && !check(res + 2, r) && r - l + 1 <= res + 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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