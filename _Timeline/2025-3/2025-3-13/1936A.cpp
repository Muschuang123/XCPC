#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 思路：
// 先找到最大的
// 然后让最大的 OR 所有数，找出一群最大的
// 找到这群最大的里面的 最小的

void solve()
{
    int n;
    cin >> n;
    int mxi = 0;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << i << ' ' << i << ' ' << mxi << ' ' << mxi << endl;
        char c;
        cin >> c;
        if (c == '>')
        {
            mxi = i;
        }
    }

    vector<int> vec;
    vec.push_back(0);
    int cur = 0;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << mxi << ' ' << cur << ' ' << mxi << ' ' << i << endl;
        char c;
        cin >> c;
        if (c == '=')
        {
            vec.push_back(i);
        }
        else if (c == '<')
        {
            cur = i;
            vec.clear();
            vec.push_back(i);
        }
    }

    int mni = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        cout << "? " << vec[i] << ' ' << vec[i] << ' ' << vec[mni] << ' ' << vec[mni] << endl;
        char c;
        cin >> c;
        if (c == '<')
        {
            mni = i;
        }
    }
    cout << "! " << mxi << ' ' << vec[mni] << endl;

}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}