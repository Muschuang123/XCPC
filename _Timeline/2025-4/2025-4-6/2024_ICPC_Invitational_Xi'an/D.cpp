#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const int maxn = 2e5 + 10;

int a[maxn], b[maxn];
ll pre[maxn], suf[maxn];

#define cln cerr << __LINE__ << "    "

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        pre[i] = pre[i - 1] + b[i];
    }
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + b[i];
    const int mx = 1e6;
    ll ans = LLONG_MAX;
    for (ll k = 0; k <= mx; k++)
    {
        unordered_map<ll, ll> mp;
        ll res = 0, t = 0, cur = 0;
        int pos = n + 1;
        for (int i = 1; i <= n; i++)
        {
            if (k * (i - 1) > mx)
            {
                res += suf[i];
                pos = i;
                break;
            }
            ll tmp = a[i] - (i - 1) * k;
            if (tmp < 0)
                cur += b[i], res += b[i];
            else
            {
                mp[tmp] += b[i];
                t = max(t, mp[tmp]);
            }
        }
        ll tot = pre[pos - 1] - cur;
        // cln << tot - t + res << endl;
        ans = min(ans, tot - t + res);
    }
    cout << ans << endl;
}