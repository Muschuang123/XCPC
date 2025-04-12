#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, b;
    cin >> a >> b;
    a++, b++;
    int ca = 0, cb = 0;
    int n;
    cin >> n;
    int fl = 0;
    for (int i = 1; i <= n; i++)
    {
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        if (w == q + e && r != q + e)
            ca++;
        if (w != q + e && r == q + e)
            cb++;
        if (!fl && ca == a)
        {
            cout << "A\n" << cb;
            fl = 1;
        }
        if (!fl && cb == b)
        {
            cout << "B\n" << ca;
            fl = 1;
        }
    }

    return 0;
}