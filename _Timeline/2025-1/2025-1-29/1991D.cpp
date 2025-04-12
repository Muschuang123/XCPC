#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * ！！！四色定理：平面图相邻点颜色不同染色至多四色。
 * 有了四色定理，那么在必须使用四种颜色的情况下，条件可以宽松一下。
 * 
 * 直接判断谁和谁相连不好判断，但是可以知道 相连的必要条件（满足其中一条）：
 *      1. (u ^ v) == 2
 *      2. (u ^ v) % 2 == 1
 * 
 * 所以我们把不超过四色的情况特判一下，
 * 超过四色的话，四色随便用，所以，按照二进制最后两位不同组合分配就可以了。
 * 这种分配方式，保证了在上述必要条件下，不可能出现相邻同色的情况。
 */ 

void solve()
{
    int n;
    cin >> n;
    if (n <= 5)
    {
        if (n == 1)
        {
            cout << "1\n";
            cout << "1\n";
        }
        if (n == 2)
        {
            cout << "2\n";
            cout << "1 2\n";
        }
        if (n == 3)
        {
            cout << "2\n";
            cout << "1 2 2\n";
        }
        if (n == 4)
        {
            cout << "3\n";
            cout << "1 2 2 3\n";
        }
        if (n == 5)
        {
            cout << "3\n";
            cout << "1 2 2 3 3\n";
        }
    }
    else
    {
        cout << "4\n";
        for (int i = 0; i < n; i++)
        {
            cout << i % 4 + 1 << " \n"[i == n - 1];
        }
    }
    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}