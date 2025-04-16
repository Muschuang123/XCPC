#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct ti {
    int h, m, s;
    ti(string t) {
        h = stoi(t.substr(0, 2));
        m = stoi(t.substr(3, 2));
        s = stoi(t.substr(6, 2));
    }
};

bool operator<(const ti &a, const ti &b) {
    return a.h < b.h || a.h == b.h && a.m < b.m || a.h == b.h && a.m == b.m && a.s < b.s;
}

bool operator==(const ti &a, const ti &b) {
    return a.h == b.h && a.m == b.m && a.s == b.s;
}

bool operator!=(const ti &a, const ti &b) {
    return !(a == b);
}

ostream &operator<<(ostream &os, const ti &a) {
    os << setw(2) << setfill('0');
    os << a.h << ':';
    os << setw(2) << setfill('0');
    os << a.m << ':';
    os << setw(2) << setfill('0');
    os << a.s;
    return os;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    set<pair<ti, ti>> ss;
    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s;
        cin >> t;
        cin >> t;
        ss.insert({ti(s), ti(t)});
    }
    ss.insert({ti("23:59:59"), ti("23:59:59")});
    
    ti la("00:00:00");
    for (auto &e : ss) {
        if (e.first != la) {
            cout << la << " - " << e.first << '\n';
        }
        la = e.second;
    }
    

    return 0;
}