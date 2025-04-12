#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> idx(n + 1), ridx(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
        idx[i] = ridx[i] = pos[i] = i;
    while (q--)
    {
        int op, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            pos[a] = idx[b];
        }
        else if (op == 2)
        {
            cin >> a >> b;
            swap(ridx[idx[a]], ridx[idx[b]]);
            swap(idx[a], idx[b]);
        }
        else 
        {
            cin >> a;
            cout << ridx[pos[a]] << '\n';
        }
    }

    return 0;
}