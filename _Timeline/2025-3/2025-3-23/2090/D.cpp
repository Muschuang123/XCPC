#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 100;

vector<int> pri;
bool not_prime[maxn];
int minp[maxn];
void euler(int n)
{
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
            minp[i] = i;
        }
        for (int j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            minp[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int p = *lower_bound(pri.begin(), pri.end(), n / 2);
    set<int> ss;
    for (int i = 1; i <= n; i++)
        ss.insert(i);
    int l = p, r = p + 1;
    int i = 1;
    vector<int> ans(1);
    for (; i <= n; i++)
    {
        if (p - l <= r - p && l >= 1)
        {
            // cout << l << ' ';
            ans.push_back(l);
            ss.erase(l);
            l--;
        }
        else if (p - l > r - p && r <= n)
        {
            // cout << r << ' ';
            ans.push_back(r);
            ss.erase(r);
            r++;
        }
        else
        {
            break;
        }
    }
    for (; i <= n; i++)
    {
        // cout << *ss.rbegin() << ' ';
        ans.push_back(*ss.rbegin());
        ss.erase(--ss.end());
    }
    // int cnt = 0;
    // i64 sum = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     sum += ans[i];
    //     if (!not_prime[(sum + i - 1) / i])
    //     {
    //         cnt++;
    //     }
    // }
    // if (cnt >= n / 3 - 1)
    // {
    //     cout << "A\n";
    // }
    // else
    // {
    //     cout << "W\n";
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
    // cout << '\n';
}

int main()
{
    euler(1e5 + 90);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}