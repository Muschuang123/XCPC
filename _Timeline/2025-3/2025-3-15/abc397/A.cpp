#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    float f;
    cin >> f;
    if (f >= 38.0)
    {
        cout << 1 << '\n';
    }
    else if (f < 37.5)
    {
        cout << 3 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }

    return 0;
}