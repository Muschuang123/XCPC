#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k, s;
    cin >> n >> k >> s;
    if (k * (n - 1) < s || k > s)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        cout << "YES\n";
    }
    
    int pos = 1;
    while (s - (n - 1) > k - 1)
    {
        s -= n - 1;
        k--;
        if (pos == 1)
            pos = n;
        else
            pos = 1;
        cout << pos << ' ';
    }

    if (s > k)
    {
        if (pos == 1)
        {
            pos += s - k + 1;
        }
        else
        {
            pos -= s - k + 1;
        }
        cout << pos << ' ';
        s -= s - k + 1;
        k--;
    }
    
    while (k--)
    {
        if (pos > 1)
            pos--;
        else 
            pos++;
        cout << pos << ' ';
    }
    

    return 0;
}