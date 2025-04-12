#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
    {
        cout << "Tu Dou\n";
    }
    else if (a * b == c)
    {
        cout << "Lv Yan\n";
    }
    else 
    {
        cout << "zhe du shi sha ya!\n";
    }
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