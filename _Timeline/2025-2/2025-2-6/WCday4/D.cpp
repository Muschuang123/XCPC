#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    if (n < m)
    {
        swap(n, m);
        cin >> b >> a;
    }
    else
    {
        cin >> a >> b;
    }
    
    vector<int> ka(26), kb(26);
    for (auto &c : a)
    {
        ka[c - 'a']++;
    }
    for (auto &c : b)
    {
        kb[c - 'a']++;
    }

    int ans = 0;
    if ((n + m) % 2 == 0)
    {
        int ch = 0;
        for (int i = 0; i < 26; i++)
        {
            if (ka[i] > kb[i])
            {
                ch += (ka[i] - kb[i]) / 2 * 2;
                ans += (ka[i] - kb[i]) % 2;
            }
            else
            {
                ans += kb[i] - ka[i];
            }
        }
        ans += max(0, ch - n + m);
        ans /= 2;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (ka[i] > kb[i] && (ka[i] - kb[i]) % 2 == 1)
            {
                ka[i]--;
                break;
            }
        }
        
        int ch = 0;
        for (int i = 0; i < 26; i++)
        {
            if (ka[i] > kb[i])
            {
                ch += (ka[i] - kb[i]) / 2 * 2;
                ans += (ka[i] - kb[i]) % 2;
            }
            else
            {
                ans += kb[i] - ka[i];
            }
        }
        ans += max(0, ch - n + m + 1);
        ans /= 2;
    }
    
    cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}