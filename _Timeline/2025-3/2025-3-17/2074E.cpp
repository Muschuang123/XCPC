#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    while (1)
    {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        int x;
        cin >> x;
        if (x == 0)
            break;
        int r = rand();
        if (r % 3 == 0) a = x;
        if (r % 3 == 1) b = x;
        if (r % 3 == 2) c = x; 
    }
    cout << "! " << a << ' ' << b << ' ' << c << endl;
}

int main()
{
    srand(time(0));
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}