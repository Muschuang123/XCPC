#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e7 + 10;
const int inf = 0x3f3f3f3f;

template <class T>
constexpr T qpow(T n, ll k)
{
    T r = 1;
    for (; k; k /= 2, n *= n)
    {
        if (k % 2)
        {
            r *= n;
        }
    }
    return r;
}

template <int MOD>
struct Zmod
{
    int x;
    Zmod(int x = 0) : x(norm(x % MOD)) {}
    Zmod(ll x) : x(norm(x % MOD)) {}

    constexpr int norm(int x) const
    {
        if (x < 0)
        {
            x += MOD;
        }
        if (x >= MOD)
        {
            x -= MOD;
        }
        return x;
    }
    static constexpr int getMod() { return MOD; }
    constexpr int val() const { return x; }
    constexpr Zmod operator-() const
    {
        Zmod val = norm(MOD - x);
        return val;
    }
    constexpr Zmod inv() const
    {
        assert(x != 0);
        return qpow(*this, MOD - 2);
    }
    friend constexpr auto &operator>>(istream &in, Zmod &j)
    {
        int v;
        in >> v;
        j = Zmod(v);
        return in;
    }
    friend constexpr auto &operator<<(ostream &o, const Zmod &j)
    {
        return o << j.val();
    }
    constexpr Zmod &operator++()
    {
        x = norm(x + 1);
        return *this;
    }
    constexpr Zmod &operator--()
    {
        x = norm(x - 1);
        return *this;
    }
    constexpr Zmod &operator+=(const Zmod &i)
    {
        x = norm(x + i.x);
        return *this;
    }
    constexpr Zmod &operator-=(const Zmod &i)
    {
        x = norm(x - i.x);
        return *this;
    }
    constexpr Zmod &operator*=(const Zmod &i)
    {
        x = (ll)(x)*i.x % MOD;
        return *this;
    }
    constexpr Zmod &operator/=(const Zmod &i) { return *this *= i.inv(); }
    constexpr Zmod &operator%=(const int &i) { return x %= i, *this; }
    friend constexpr Zmod operator+(const Zmod i, const Zmod j) { return Zmod(i) += j; }
    friend constexpr Zmod operator-(const Zmod i, const Zmod j) { return Zmod(i) -= j; }
    friend constexpr Zmod operator*(const Zmod i, const Zmod j) { return Zmod(i) *= j; }
    friend constexpr Zmod operator/(const Zmod i, const Zmod j) { return Zmod(i) /= j; }
    friend constexpr Zmod operator%(const Zmod i, const int j) { return Zmod(i) %= j; }
    friend constexpr bool operator==(const Zmod i, const Zmod j) { return i.val() == j.val(); }
    friend constexpr bool operator!=(const Zmod i, const Zmod j) { return i.val() != j.val(); }
    friend constexpr bool operator<(const Zmod i, const Zmod j) { return i.val() < j.val(); }
    friend constexpr bool operator>(const Zmod i, const Zmod j) { return i.val() > j.val(); }
};

constexpr int MOD[] = {998244353, 1000000007};
using Z = Zmod<MOD[1]>; //<-修改模数在这里

Z power(ll n)
{
    return qpow(Z(2), n);
}

struct Comb
{
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb()
    {
        init(n);
    }

    void init(int m)
    {
        m = std::min(m, Z::getMod() - 1);
        if (m <= n)
            return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++)
        {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--)
        {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m)
    {
        if (m > n)
            init(2 * m);
        return _fac[m];
    }
    Z invfac(int m)
    {
        if (m > n)
            init(2 * m);
        return _invfac[m];
    }
    Z inv(int m)
    {
        if (m > n)
            init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m)
    {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

Z f[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    f[1] = 1, f[2] = 1;
    for (int i = 3; i < maxn; i++)
        f[i] = f[i - 1] + f[i - 2];
    int lst = 0;
    Z ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans += f[max(0, 2 * (n - i - 1) + lst)];
            lst++;
        }
    }
    ans += f[lst];
    cout << ans << endl;
}