#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = rand() % 100 + 1;
    cout << t << '\n';
    while (t--)
    {
        int x = rand();
        int y = rand();
        while (y == x)
        {
            y = rand();
        }
        cout << x << ' ' << y << '\n';
    }

    return 0;
}