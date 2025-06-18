#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    // s2.push_back('A');
    vector<int> ok;

    vector<int> ne(m + 1);
    for (int i = 2, j = 0; i <= m; i++) {
        while (j > 0 && s2[j + 1] != s2[i]) j = ne[j];
        if (s2[j + 1] == s2[i]) j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++) {
        while (j > 0 && s2[j + 1] != s1[i]) j = ne[j];
        if (s2[j + 1] == s1[i]) j++;
        if (j == m) {
            ok.push_back(i - j + 1);
            j = ne[j];
        }
    }

    for (auto &e : ok) {
        cout << e << '\n';
    }
    for (int i = 1; i <= m; i++) {
        cout << ne[i] << ' ';
    }

    return 0;
}