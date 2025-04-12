#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    this method is based on binary searching on answer (power of the spell).

    for each search, we need to check the whats range
        in which we can put the first attack.
    if the range isn't exist, "bool check()" will return false.

    for the left limit of the range,
        "mid - a[i]" is meaning the rest power of killing the monster to waste.
            if it < i - 1, thats mean we can't put the first attack on it left.
            so let the "l = i"
    for the right limit of the range, 
        as the same way for "mid - a[i] < n - i".
    
    NOTICE that we need to figure out the most left r and most right l.
*/

int n, mxind;
vector<int> a;

bool check(int mid)
{
    // take the maximum l and minimum r.
    int l = 1, r = n;
    for (int i = 1; i <= n; i++)
    {
        if (mid - a[i] < n - i)
            r = min(r, i);
        if (mid - a[i] < i - 1)
            l = i;
    }
    return l <= r;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = *max_element(a.begin() + 1, a.end()) - 1, r = 1e18;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    
    cout << r;

    return 0;
}