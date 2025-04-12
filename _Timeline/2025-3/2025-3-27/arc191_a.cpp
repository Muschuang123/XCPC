#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    // 最后一个数字肯定是要放的，先留着，等都放完再放这个
    string s, t;
    cin >> s >> t;
    vector<int> vis(s.size());
    priority_queue<char> q;
    for (int i = 0; i < m - 1; i++)
        q.push(t[i]);
    for (int i = 0; i < n; i++)
    {
        if (q.size() && s[i] < q.top())
        {
            s[i] = q.top();
            vis[i] = 1;
            q.pop();
        }
    }
    int fl = 0;
    char dummy = 0;
    for (int i = 0; i < n; i++)
    {
        if (fl == 0 && s[i] < t.back())
        {
            dummy = s[i];
            s[i] = t.back();
            if (vis[i])
                fl = 2;
            else 
                fl = 1;
        }
        if (fl == 2 && s[i] < dummy)
        {
            swap(s[i], dummy);
            if (vis[i])
                fl = 2;
            else 
                fl = 1;
        }
    }
    if (fl == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t.back())
            {
                s[i] = t.back();
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            s.back() = t.back();
    }
    cout << s << '\n';

    return 0;
}