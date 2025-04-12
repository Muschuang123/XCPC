#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    let x < y both is arbitrary number from 1 to n.
    if y % x == 0, just let a[x] = max(a[x], a[y]). 

    we do this update by two "for ()". by: 
    (n + n/2 + n/3 + n/4 + ... + n/n) ≈ nln(n).

    Notice: we just sort the array:
        sort(a.begin() + 1, a.end(), greater<int>());
        
    if the bigger number appeared, we don't care the smaller one.

    so the answer is 
        ans = (ans + a[i] * ksm(2, n - i)) % mod;
    for i from 1 to n.

*/

const int mod = 998244353;
const int maxn = 1e5 + 7;

int ksm(int a, int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            a[i] = max(a[i], a[i * j]);
        }
    }

    sort(a.begin() + 1, a.end(), greater<int>());

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + a[i] * ksm(2, n - i)) % mod;
    }
    cout << ans << '\n';

    return 0;
}