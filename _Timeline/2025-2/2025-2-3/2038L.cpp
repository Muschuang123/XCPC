#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;

    // 1 * 18 + 2 * 21 AND 2 * 18 + 1 * 21
    ans += n / 3 * 2; 
    // 2 * 25
    ans += (n + 1) / 2; 
    if (n % 3 == 1)
    {
        ans += 1;
    }
    else if (n % 3 == 2)
    {
        if (n % 2)
            ans += 1;
        else 
            ans += 2;
    }
    

    cout << ans << '\n';

    return 0;
}