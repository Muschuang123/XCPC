#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, b;
    cin >> a >> b;
    a += b;
    cout << a - 16 << '\n';
    cout << a - 3 << '\n';
    cout << a - 1 << '\n';
    cout << a;

    return 0;
}