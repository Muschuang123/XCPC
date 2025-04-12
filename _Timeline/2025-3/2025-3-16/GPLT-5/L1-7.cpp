#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int res = 1e9;
    int l = 0, r = 0;
    for (int i = 1, j = c - 1; j > 0; i++, j--)
    {
        if (a % i == 0 && b % j == 0 && abs(a / i - b / j) < res &&
            a / i != 1 && b / j != 1)
        {
            res = abs(a / i - b / j);
            l = i, r = j;
        }
    }
    if (res == 1e9)
    {
        cout << "No Solution\n";
    }
    else
    {
        cout << l << ' ' << r;
    }

    return 0;
}