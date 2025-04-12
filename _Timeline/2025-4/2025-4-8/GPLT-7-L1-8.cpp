#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    string s;
    int i = 1;
    vector<int> t = a;
    while (cin >> s)
    {
        if (s == "End") {
            break;
        }
        if (i == n + 1) {
            t = a;
            i = 1;
        }

        if (t[i] == 0) {
            if (s == "ChuiZi") {
                cout << "JianDao\n";
            } else if (s == "JianDao") {
                cout << "Bu\n";
            } else {
                cout << "ChuiZi\n";
            }
        } else {
            if (s == "ChuiZi") {
                cout << "Bu\n";
            } else if (s == "JianDao") {
                cout << "ChuiZi\n";
            } else {
                cout << "JianDao\n";
            }
        }

        t[i]--;

        if (t[i] == -1) {
            i++;
        }
    }

    return 0;
}