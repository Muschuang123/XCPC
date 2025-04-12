#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 x, y;
    cin >> x >> y;
    // if (x == y)
    // {
    //     cout << -1 << '\n';
    //     return;
    // }
    i64 k = 0;
    // int la = 0;
    for (i64 i = 0; i <= 40; i++)
    {
        i64 dx = x + k >> i & 1, dy = y + k >> i & 1;
        i64 dx2 = x + k >> i + 1 & 1, dy2 = y + k >> i + 1 & 1;
        // if (dx2 == 1 && dy2 == 1 && (dx ^ dy))
        if (dx == 1 && dy == 1 || !(dx2 ^ dy2) && (dx ^ dy))
        {
            k += 1LL << i;
            // la = 1;
        }
        // else if (la)
        // {
        //     k += 1LL << i;
        //     la = 0;
        // }
    }
    // 010011
    // 001010

    // 01101
    // 01001

    // 1011
    // 1101

    // 000100100100100100100100
    // 000010010010010010010100
    // 000000000000000000011100
    if (x + k + y + k == ((x + k) ^ (y + k)))
    {
        cout << k << '\n';
    }
    else
    {
        cout << "-1\n";
    }
    // cout << k << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}