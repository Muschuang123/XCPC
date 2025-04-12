#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    string x;
    cin >> n >> x >> m >> k;
    if (k == n)
    {
        cout << "mei you mai " <<  x <<  " de";
    }
    else if (k == m)
    {
        cout << "kan dao le mai " <<  x <<  " de";
    }
    else 
    {
        cout << "wang le zhao mai " << x << " de";
    }

    return 0;
}