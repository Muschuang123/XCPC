#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 n;
    cin >> n;
    i64 ans = 0;
    n /= 2;
    ans += sqrtl(n);
    n /= 2; 
    ans += sqrtl(n);
    cout << ans << '\n';

    return 0;
}