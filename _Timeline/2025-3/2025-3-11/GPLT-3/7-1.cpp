#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        cnt += s[i] == '2';
    double d = 1.0 * cnt / (s.size() - (s.front() == '-'));
    if (s.front() == '-')
        d *= 1.5;
    if (s.back() - '0' & 1 ^ 1)
        d *= 2;
    d *= 100;
    cout << fixed << setprecision(2) << d << '%' << '\n';

    return 0;
}