// https://ac.nowcoder.com/acm/contest/108300/I
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

template <unsigned MOD>
struct ModInt {
    static constexpr int mod = MOD;
    unsigned v;
    ModInt() : v(0) {}
    template <class T, enable_if_t<is_integral<T>::value> * = nullptr>
    ModInt(T x) {
        x %= mod;
        if (x < 0)
            x += mod;
        v = x;
    }
    ModInt(const string &str) {
        v = 0;
        size_t i = 0;
        if (str.front() == '-')
            i += 1;
        while (i < str.size()) {
            assert(isdigit(str[i]));
            v = (v * 10ull % MOD + str[i] - '0') % MOD;
            i += 1;
        }
        if (str.front() == '-' && v)
            v = MOD - v;
    }
    ModInt inv() const { return qpow(*this, MOD - 2); }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt() - *this; }
    friend int raw(const ModInt &self) { return self.v; }
    friend istream &operator>>(istream &is, ModInt &self) {
        string str;
        is >> str;
        self = str;
        return is;
    }
    friend ostream &operator<<(ostream &os, const ModInt &self) {
        return os << raw(self);
    }
    ModInt &operator+=(const ModInt &rhs) {
        v += rhs.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &rhs) {
        v -= rhs.v;
        if (v >= MOD)
            v += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &rhs) {
        v = static_cast<unsigned>(1ull * v * rhs.v % MOD);
        return *this;
    }
    ModInt &operator/=(const ModInt &rhs) {
        static constexpr size_t ilim = 1 << 20;
        static ModInt inv[ilim + 10];
        static int sz = 0;
        assert(rhs.v);
        if (rhs.v > ilim)
            return *this *= qpow(rhs, mod - 2);
        if (!sz)
            inv[1] = sz = 1;
        while (sz < (int)rhs.v) {
            for (int i = sz + 1; i <= sz << 1; i++)
                inv[i] = -mod / i * inv[mod % i];
            sz <<= 1;
        }
        return *this *= inv[rhs.v];
    }
    template <class T>
    friend ModInt qpow(ModInt a, T b) {
        ModInt r = 1;
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                r *= a;
        return r;
    }
    friend ModInt operator+(ModInt lhs, const ModInt &rhs) { return lhs += rhs; }
    friend ModInt operator-(ModInt lhs, const ModInt &rhs) { return lhs -= rhs; }
    friend ModInt operator*(ModInt lhs, const ModInt &rhs) { return lhs *= rhs; }
    friend ModInt operator/(ModInt lhs, const ModInt &rhs) { return lhs /= rhs; }
    friend bool operator==(const ModInt &lhs, const ModInt &rhs) { return lhs.v == rhs.v; }
    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) { return lhs.v != rhs.v; }
};

typedef ModInt<998244353> Z;

int glim(const int &x) { return 1 << (32 - __builtin_clz(x - 1)); }
int bitctz(const int &x) { return __builtin_ctz(x); }

struct Poly : vector<Z> {
    Poly() {}
    explicit Poly(int n) : vector<Z>(n) {}
    Poly(const vector<Z> &vec) : vector<Z>(vec) {}
    Poly(initializer_list<Z> il) : vector<Z>(il) {}
    Z operator()(const Z &x) const;
    Poly &cut(int lim);
    void ntt(int op);

    Poly abst(int l = 0, int r = -1) const {
        if (r == -1)
            r = size();
        vector<Z> v(r - l);
        for (int i = l; i < size() && i < r; i++)
            v[i - l] = (*this)[i];
        return Poly(v);
    }
    inline Poly derivative() const {
        Poly res(size() - 1);
        for (int i = 1; i < size(); i++)
            res[i - 1] = (*this)[i] * i;
        return res;
    }
};

void print(const Poly &a) {
    for (size_t i = 0; i < a.size(); i++)
        printf("%d, ", raw(a[i]));
    printf("\n");
}
istream &operator>>(istream &is, Poly &a) {
    for (auto &x : a)
        is >> x;
    return is;
}
ostream &operator<<(ostream &os, const Poly &a) {
    bool flag = false;
    for (auto &x : a) {
        if (flag)
            os << " ";
        else
            flag = true;
        os << x;
    }
    return os;
}
Z Poly::operator()(const Z &x) const {
    const auto &a = *this;
    Z res = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        res = res * x + a[i];
    }
    return res;
}
Poly &Poly::cut(int lim) {
    resize(lim);
    return *this;
}
void Poly::ntt(int op) {
    static bool wns_flag = false;
    static vector<Z> wns;
    if (!wns_flag) {
        wns_flag = true;
        for (int j = 1; j <= 23; j++) {
            wns.push_back(qpow(Z(3), raw(Z(-1)) >> j));
        }
    }
    vector<Z> &a = *this;
    int n = a.size();
    for (int i = 1, r = 0; i < n; i++) {
        r ^= n - (1 << (bitctz(n) - bitctz(i) - 1));
        if (i < r)
            std::swap(a[i], a[r]);
    }
    vector<Z> w(n);
    for (int k = 1, len = 2; len <= n; k <<= 1, len <<= 1) {
        Z wn = wns[bitctz(k)];
        for (int i = raw(w[0] = 1); i < k; i++)
            w[i] = w[i - 1] * wn;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < k; j++) {
                Z x = a[i + j], y = a[i + j + k] * w[j];
                a[i + j] = x + y, a[i + j + k] = x - y;
            }
        }
    }
    if (op == -1) {
        Z iz = Z(1) / n;
        for (int i = 0; i < n; i++)
            a[i] *= iz;
        reverse(a.begin() + 1, a.end());
    }
}
Poly concalc(int n, vector<Poly> vec, const function<Z(vector<Z>)> &func) {
    int lim = glim(n);
    int m = vec.size();
    for (auto &f : vec)
        f.resize(lim), f.ntt(1);
    vector<Z> tmp(m);
    Poly ret(lim);
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < m; j++)
            tmp[j] = vec[j][i];
        ret[i] = func(tmp);
    }
    ret.ntt(-1);
    return ret;
}
Poly getInv(const Poly &a, int lim) {
    Poly b{1 / a[0]};
    for (int len = 2; len <= glim(lim); len <<= 1) {
        Poly c = vector<Z>(a.begin(), a.begin() + min(len, (int)a.size()));
        b = concalc(len << 1, {b, c}, [](vector<Z> vec) { return vec[0] * (2 - vec[0] * vec[1]); })
                .cut(len);
    }
    return b.cut(lim);
}
Poly operator+=(Poly &a, const Poly &b) {
    if (a.size() < b.size())
        a.resize(b.size());
    for (size_t i = 0; i < b.size(); i++)
        a[i] += b[i];
    return a;
}
Poly operator-=(Poly &a, const Poly &b) {
    if (a.size() < b.size())
        a.resize(b.size());
    for (size_t i = 0; i < b.size(); i++)
        a[i] -= b[i];
    return a;
}
Poly operator*=(Poly &a, const Z &k) {
    if (k == 1)
        return a;
    for (size_t i = 0; i < a.size(); i++)
        a[i] *= k;
    return a;
}
Poly operator/=(Poly &a, const Z &k) { return a *= 1 / k; }
Poly operator<<=(Poly &a, const int &k) {
    // mnltiple by x^k
    a.insert(a.begin(), k, 0);
    return a;
}
Poly operator>>=(Poly &a, const int &k) {
    // divide by x^k
    a.erase(a.begin(), a.begin() + min(k, (int)a.size()));
    return a;
}
Poly operator*(const Poly &a, const Poly &b) {
    if (a.empty() || b.empty())
        return {};
    int rlen = a.size() + b.size() - 1;
    int len = glim(rlen);
    if (1ull * a.size() * b.size() <= 1ull * len * bitctz(len)) {
        Poly ret(rlen);
        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < b.size(); j++)
                ret[i + j] += a[i] * b[j];
        return ret;
    } else {
        return concalc(len, {a, b},
                       [](vector<Z> vec) { return vec[0] * vec[1]; })
            .cut(rlen);
    }
}

Poly operator/(Poly a, Poly b) {
    if (a.size() < b.size())
        return {};
    int rlen = a.size() - b.size() + 1;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a = (a * getInv(b, rlen)).cut(rlen);
    reverse(a.begin(), a.end());
    return a;
}
Poly operator-(Poly a, const Poly &b) { return a -= b; }
Poly operator%(const Poly &a, const Poly &b) { return (a - (a / b) * b).cut(b.size() - 1); }
Poly operator*=(Poly &a, const Poly &b) { return a = a * b; }
Poly operator/=(Poly &a, const Poly &b) { return a = a / b; }
Poly operator%=(Poly &a, const Poly &b) { return a = a % b; }
Poly operator+(Poly a, const Poly &b) { return a += b; }
Poly operator*(Poly a, const Z &k) { return a *= k; }
Poly operator*(const Z &k, Poly a) { return a *= k; }
Poly operator/(Poly a, const Z &k) { return a /= k; }
Poly operator<<(Poly a, const int &k) { return a <<= k; }
Poly operator>>(Poly a, const int &k) { return a >>= k; }

Poly getDev(Poly a) {
    a >>= 1;
    for (size_t i = 1; i < a.size(); i++)
        a[i] *= i + 1;
    return a;
}

Poly getInt(Poly a) {
    a <<= 1;
    for (size_t i = 1; i < a.size(); i++)
        a[i] /= i;
    return a;
}

Poly getLn(const Poly &a, int lim) {
    assert(a[0] == 1);
    return getInt(getDev(a) * getInv(a, lim)).cut(lim);
}

Poly getExp(const Poly &a, int lim) {
    assert(a[0] == 0);
    Poly b{1};
    for (int len = 2; len <= glim(lim); len <<= 1) {
        Poly c = vector<Z>(a.begin(), a.begin() + min(len, (int)a.size()));
        b = concalc(len << 1, {b, getLn(b, len), c}, [](vector<Z> vec) { return vec[0] * (1 - vec[1] + vec[2]); })
                .cut(len);
    }
    return b.cut(lim);
}

Poly qpow(const Poly &a, string k, int lim) {
    size_t i = 0;
    while (i < a.size() && a[i] == 0)
        i += 1;
    if (i == a.size() || (i > 0 && k.size() >= 9) ||
        1ull * i * raw(Z(k)) >= 1ull * lim)
        return Poly(lim);
    lim -= i * raw(Z(k));
    return getExp(getLn(a / a[i] >> i, lim) * k, lim) * qpow(a[i], raw(ModInt<Z::mod - 1>(k))) << i * raw(Z(k));
}

Poly qpow(const Poly &a, ll k, int lim) {
    size_t i = 0;
    while (i < a.size() && a[i] == 0)
        i += 1;
    if (i == a.size() || (i > 0 && k >= 1e9) ||
        1ull * i * k >= 1ull * lim)
        return Poly(lim);
    lim -= i * k;
    return getExp(getLn(a / a[i] >> i, lim) * k, lim) * qpow(a[i], raw(ModInt<Z::mod - 1>(k))) << i * k;
}

Z sqrt(const Z &c) {
    static const auto check = [](Z c) {
        return qpow(c, (Z::mod - 1) >> 1) == 1;
    };
    if (raw(c) <= 1)
        return 1;
    if (!check(c))
        throw "No solution!";
    static mt19937 rng{random_device{}()};
    Z a = rng();
    while (check(a * a - c))
        a = rng();
    typedef pair<Z, Z> number;
    const auto mul = [=](number x, number y) {
        return make_pair(x.first * y.first + x.second * y.second * (a * a - c), x.first * y.second + x.second * y.first);
    };
    const auto qpow = [=](number a, int b) {
        number r = {1, 0};
        for (; b; b >>= 1, a = mul(a, a))
            if (b & 1)
                r = mul(r, a);
        return r;
    };
    Z ret = qpow({a, 1}, (Z::mod + 1) >> 1).first;
    return min(raw(ret), raw(-ret));
}

Poly getSqrt(const Poly &a, int lim) {
    Poly b{sqrt(a[0])};
    for (int len = 2; len <= glim(lim); len <<= 1) {
        Poly c = vector<Z>(a.begin(), a.begin() + min(len, (int)a.size()));
        b = (c * getInv(b * 2, len) + b / 2).cut(len);
    }
    return b.cut(lim);
}

template <class T>
Z divide_at(Poly f, Poly g, T n) {
    for (; n; n >>= 1) {
        Poly r = g;
        for (size_t i = 1; i < r.size(); i += 2)
            r[i] *= -1;
        f *= r;
        g *= r;
        for (size_t i = n & 1; i < f.size(); i += 2)
            f[i >> 1] = f[i];
        f.resize((f.size() + 1) >> 1);
        for (size_t i = 0; i < g.size(); i += 2)
            g[i >> 1] = g[i];
        g.resize((g.size() + 1) >> 1);
    }
    return f.empty() ? 0 : f[0] / g[0];
}

template <class T>
Z linear_rec(Poly a, Poly f, T n) {
    // a[n] = sum_i f[i] * a[n - i]
    a.resize(f.size() - 1);
    f = Poly{1} - f;
    Poly g = a * f;
    g.resize(a.size());
    return divide_at(g, f, n);
}

Poly BM(Poly a) {
    Poly ans, lst;
    int w = 0;
    Z delta = 0;
    for (size_t i = 0; i < a.size(); i++) {
        Z tmp = -a[i];
        for (size_t j = 0; j < ans.size(); j++)
            tmp += ans[j] * a[i - j - 1];
        if (tmp == 0)
            continue;
        if (ans.empty()) {
            w = i;
            delta = tmp;
            ans = vector<Z>(i + 1, 0);
        } else {
            auto now = ans;
            Z mul = -tmp / delta;
            if (ans.size() < lst.size() + i - w)
                ans.resize(lst.size() + i - w);
            ans[i - w - 1] -= mul;
            for (size_t j = 0; j < lst.size(); j++)
                ans[i - w + j] += lst[j] * mul;
            if (now.size() <= lst.size() + i - w) {
                w = i;
                lst = now;
                delta = tmp;
            }
        }
    }
    return ans << 1;
}

Poly lagrange(const vector<pair<Z, Z>> &a) {
    Poly ans(a.size()), product{1};
    for (size_t i = 0; i < a.size(); i++) {
        product *= Poly{-a[i].first, 1};
    }
    auto divide2 = [&](Poly a, Z b) {
        Poly res(a.size() - 1);
        for (size_t i = (int)a.size() - 1; i >= 1; i--) {
            res[i - 1] = a[i];
            a[i - 1] -= a[i] * b;
        }
        return res;
    };
    for (size_t i = 0; i < a.size(); i++) {
        Z denos = 1;
        for (size_t j = 0; j < a.size(); j++) {
            if (i != j)
                denos *= a[i].first - a[j].first;
        }
        Poly numes = divide2(product, -a[i].first);
        ans += a[i].second / denos * numes;
    }
    return ans;
}

Poly mul_T(Poly a, Poly b) {
    reverse(b.begin(), b.end());
    int n = a.size(), m = b.size();
    a *= b;
    return a.abst(m - 1, n + m - 1);
}

vector<Z> multipoint(Poly f, vector<Z> v) {
    int N = v.size();
    int n = max(f.size(), v.size());
    f.resize(n + 1);
    v.resize(n);
    vector<Z> res(n);
    vector<Poly> Q(4 * n + 1);
    auto dfs_Q = [&](auto self, int x, int l, int r) {
        if (l == r) {
            Q[x] = Poly(vector<Z>{1, -v[l]});
            return;
        }
        int m = (l + r) >> 1;
        self(self, x << 1, l, m);
        self(self, x << 1 | 1, m + 1, r);
        Q[x] = Q[x << 1] * Q[x << 1 | 1];
    };
    dfs_Q(dfs_Q, 1, 0, n - 1);
    auto dfs = [&](auto self, int x, int l, int r, auto F) {
        F.resize(r - l + 1);
        if (l == r) {
            res[l] = F[0];
            return;
        }
        int m = (l + r) >> 1;
        self(self, x << 1, l, m, mul_T(F, Q[x << 1 | 1]));
        self(self, x << 1 | 1, m + 1, r, mul_T(F, Q[x << 1]));
    };
    dfs(dfs, 1, 0, n - 1, mul_T(f, getInv(Q[1], Q[1].size())));
    res.resize(N);
    return res;
}

Poly interpolate(vector<Z> a, vector<Z> b) {
    int n = a.size();
    vector<Poly> Q(4 * n + 1);
    auto dfs_Q = [&a, &Q](auto self, int x, int l, int r) {
        if (l == r)
            return Q[x] = Poly(vector<Z>{-a[l], 1});
        int m = (l + r) >> 1;
        return Q[x] = self(self, x << 1, l, m) * self(self, x << 1 | 1, m + 1, r);
    };
    vector<Z> q = multipoint(dfs_Q(dfs_Q, 1, 0, n - 1).derivative(), a);
    vector<Z> T;
    for (int i = 0; i < n; i++)
        T.push_back(b[i] / q[i]);
    auto dfs = [&Q, &T](auto self, int x, int l, int r) {
        if (l == r)
            return Poly(vector<Z>{T[l]});
        int m = (l + r) >> 1;
        return self(self, x << 1, l, m) * Q[x << 1 | 1] + self(self, x << 1 | 1, m + 1, r) * Q[x << 1];
    };
    return dfs(dfs, 1, 0, n - 1);
}

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }

    void init(int m) {
        m = std::min(m, 998244353 - 1);
        if (m <= n)
            return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n)
            init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n)
            init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n)
            init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
    Z perf(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m);
    }
    Z C(ll n, ll m) {
        Z res = 1;
        for (int i = 0; i < m; i++)
            res = res * (n - i) / (m - i);
        return res;
    }
    Z lucas(ll a, ll b) {
        if (a < 0 || b < 0 || b > a)
            return 0;
        int p = 998244353;
        if (a < p && b < p)
            return binom(a, b);
        return lucas(a / p, b / p) * binom(a % p, b % p);
    }
} comb;

Z ans[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q, k;
    cin >> Q >> k;
    const int n = 2e5;
    Poly g(n + 1), f(n + 1);
    for (int i = 0; i <= n; i++)
        f[i] = qpow(comb.invfac(i), k + 1);
    f = getLn(f, n + 1);
    for (int i = 1; i <= n; i++) {
        Z pw = 1, c = qpow(comb.inv(i), k + 1);
        for (int j = 0; i * j <= n; j++) {
            g[i * j] += f[j] * pw;
            pw *= c;
        }
    }
    g = getExp(g, n + 1);
    for (int i = 0; i <= n; i++)
        ans[i] = g[i] * qpow(comb.fac(i), k + 1); // 还要加上(n!)的(k + 1)才是最终答案
    while (Q--) {
        int id;
        cin >> id;
        cout << ans[id] << endl;
    }
}