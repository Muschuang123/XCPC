#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e7 + 7;
int sg[maxn];

vector<int> pri;
bool not_prime[maxn];
// int minp[maxn];
void euler(int n)
{
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 0;
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
            sg[i] = pri.size();
            // minp[i] = i;
        }
        for (int j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            // minp[i * j] = j;
            sg[i * j] = sg[j];
            if (i % j == 0)
                break;
        }
    }
    for (int i = 2; i <= n; i += 2)
        sg[i]--;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans ^= sg[x];
    }
    cout << (ans ? "Alice" : "Bob") << '\n';
}

void brute()
{
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 0;
    for (int k = 3; k <= 50; k++)
    {
        vector<int> nx;
        for (int i = 0; i <= k; i++)
        {
            if (__gcd(k, i) == 1)
                nx.push_back(sg[i]);
        }
        // mex
        sort(nx.begin(), nx.end());
        unique(nx.begin(), nx.end());
        int p = 0;
        for (int i = 0; i <= 1e6; i++, p++)
        {
            if (p == nx.size() || nx[p] != i)
                break;
        }
        sg[k] = p;
    }

    for (int i = 0; i <= 50; i++)
    {
        cout << sg[i] << ' ';
    }
}

int main()
{
    // brute();
    euler(1e7);
    // cout << '\n';
    // for (int i = 0; i <= 50; i++)
    // {
    //     cout << sg[i] << ' ';
    // }
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}