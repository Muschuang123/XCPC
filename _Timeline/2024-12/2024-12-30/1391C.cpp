#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    for all permutation of the array, we discuss the case of can't make the cycle.
    
    just let the array have no Valley. (Valley: (e.g. [2, 1, 3], [4, 2, 3]....))
    
    then we can put the number to array by sequence: 1, 2, 3, 4. 

    for every number, we just can let it go to front or end.

    [1, ......]  or  [......, 1]
    [1, 2, ......] or [1, ......, 2] or [......, 2, 1] or [2, ......, 1]
    .....

    for the number n, just no choice.

    so the answer is: factorial[n] - 2^(n - 1).

    pay attention to the modulo.

*/

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int f[maxn];

void init()
{
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        f[i] = f[i - 1] * i % mod;
    }
}

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

    init();

    int n;
    cin >> n;

    cout << (f[n] - ksm(2, n - 1) + mod) % mod;

    return 0;
}