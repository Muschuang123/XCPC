#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e6 + 6;

vector<int> pri;
bool not_prime[maxn];
int minp[maxn];
int nump[maxn];
vector<int> vec;
void euler(int n) {
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            pri.push_back(i);
            minp[i] = i;
        }
        for (int j : pri) {
            if (i * j > n) {
                break;
            }
            not_prime[i * j] = true;
            minp[i * j] = j;
            if (i % j == 0) {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int t = i;
        int res = 0;
        while (t != 1) {
            res++;
            int tp = minp[t];
            while (t % tp == 0) {
                t /= tp;
            }
        }
        nump[i] = res;
    }
    for (int i = 1; i <= n; i++) {
        if (nump[i] == 2) {
            vec.push_back(i);
        }
    }
}

void solve() {
    i64 x;
    cin >> x;
    x = sqrtl(x);
    i64 t = *--upper_bound(vec.begin(), vec.end(), x);
    cout << t * t << '\n';
}

int main() {
    euler(1e6 + 4);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}