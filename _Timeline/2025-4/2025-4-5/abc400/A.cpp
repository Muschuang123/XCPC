#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a;
    cin >> a;
    if (400 % a == 0) {
        cout << 400 / a;
    } else {
        cout << -1;
    }

    return 0;
}