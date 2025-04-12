#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    for every present: every gift can be exist or not. 
        just check the corner case: every gift is all no exist. 
    
    the number of gift: m 
    the number of present: n

    so the answer is  (2^m - 1)^n
*/

const int mod = 1e9 + 7;

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

    int n, m;
    cin >> n >> m;

    cout << ksm((ksm(2, m) - 1), n);
    

    return 0;
}