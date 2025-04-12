#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll k = 0; k <= a - 1; k++)    
    {
        ll x = (2 * a - (2 * k + 1)) * b / (2 * a);
        ans += x;
        if (2 * a * x + a <= (2 * a - (2 * k + 1)) * b)
            ans++;
    }
    cout << ans << endl;
}