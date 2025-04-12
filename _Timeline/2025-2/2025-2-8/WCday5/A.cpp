#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 x;
    char op;
    cin >> x >> op;
    if (op == '*')
    {
        cout << x << ' ' << 1 << '\n';
    }
    if (op == '+')
    {
        cout << x - 1LL << ' ' << 1 << '\n';
    }
    if (op == '-')
    {
        cout << x + 1LL << ' ' << 1 << '\n';
    }

    return 0;
}