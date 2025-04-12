#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fa;
int fin(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = fin(fa[x]);
}

void merg(int x, int y)
{
    fa[fin(x)] = fin(y);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            merg(a[i], i);
    }

    vector<int> father(n + 1);
    for (int i = 1; i <= n; i++)
    {
        father[fin(i)]++;
    }

    int s = 1;
    int p = q;
    while (a[p] != 0)
    {
        p = a[p];
        s++;
    }
    

    vector<int> len;
    father[fin(q)] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (father[i])
            len.push_back(father[i]);
    }

    sort(len.begin(), len.end());

    vector<bool> ok(n + 1);
    for (int i : len)
    {
        for (int j = n; j >= i; j--)
        {
            ok[j] = (ok[j] | ok[j - i]);
        }
        ok[i] = 1;
    }

    cout << s << '\n';
    for (int i = 0; i <= n; i++)
    {
        if (ok[i])
            cout << i + s << '\n';
    }

    return 0;
}