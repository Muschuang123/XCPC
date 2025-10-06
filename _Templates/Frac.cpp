template <class T>
struct frac {
    T a, b;
    frac(T _a, T _b) : a(_a), b(_b) {
        norm(a, b);
    }
    frac() : frac(0, 1) {}
    frac(T _a) : frac(_a, 1) {}
    explicit operator double() const {
        return 1.0 * a / b;
    }
    void norm(T &a, T &b) {
        T g = gcd(a, b);
        a /= g, b /= g;
        if (b < 0) a = -a, b = -b;
    }
    frac &operator+=(const frac &rhs) {
        a = a * rhs.b + rhs.a * b;
        b *= rhs.b;
        norm(a, b);
        return *this;
    }
    frac &operator-=(const frac &rhs) {
        a = a * rhs.b - rhs.a * b;
        b *= rhs.b;
        norm(a, b);
        return *this;
    }
    frac &operator*=(const frac &rhs) {
        a *= rhs.a;
        b *= rhs.b;
        norm(a, b);
        return *this;
    }
    frac &operator/=(const frac &rhs) {
        a *= rhs.b;
        b *= rhs.a;
        norm(a, b);
        return *this;
    }
    friend ostream &operator<<(ostream &os, frac x) {
        T g = gcd(x.a, x.b);
        if (x.b == g) {
            return os << x.a / g;
        } else {
            return os << x.a / g << "/" << x.b / g;
        }
    }
    friend frac operator+(frac lhs, const frac &rhs) { return lhs += rhs; }
    friend frac operator-(frac lhs, const frac &rhs) { return lhs -= rhs; }
    friend frac operator*(frac lhs, const frac &rhs) { return lhs *= rhs; }
    friend frac operator/(frac lhs, const frac &rhs) { return lhs /= rhs; }
    friend frac operator-(const frac &a) { return frac(-a.a, a.b); }
    friend bool operator==(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b == rhs.a * lhs.b; }
    friend bool operator!=(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b != rhs.a * lhs.b; }
    friend bool operator<(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b < rhs.a * lhs.b; }
    friend bool operator>(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b > rhs.a * lhs.b; }
    friend bool operator<=(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b <= rhs.a * lhs.b; }
    friend bool operator>=(const frac &lhs, const frac &rhs) { return lhs.a * rhs.b >= rhs.a * lhs.b; }
};