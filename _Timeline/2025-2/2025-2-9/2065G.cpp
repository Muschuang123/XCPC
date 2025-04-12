#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e5 + 5;

vector<i64> pri;
bool not_prime[maxn];
void euler(i64 n)
{
    not_prime[0] = not_prime[1] = 1;
    for (i64 i = 2; i <= n; i++)
    {
        if (!not_prime[i])
            pri.push_back(i);
        for (i64 j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    i64 ans = 0;
    i64 sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!not_prime[a[i]])
        {
            sum++;
            b[a[i]]++;
            ans += sum;
            ans -= b[a[i]];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (not_prime[a[i]])
        for (int j = 2; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0 && !not_prime[j] && !not_prime[a[i] / j])
            {
                b[a[i]]++;
                ans += b[j] + b[a[i] / j] + b[a[i]];
                if (j == a[i] / j)
                    ans -= b[j];
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    euler(2e5);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}