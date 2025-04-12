#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> ans;
    vector<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if (a.empty() || a.back() > c)
        {
            a.push_back(c);
        }
        else
        {
            if (b.empty() || b.back() < c)
            {
                b.push_back(c);
            }
            else
            {
                ans.push_back(a.size());
                a.clear();
                while (b.size() && b.back() > c)   
                {
                    a.push_back(b.back());
                    b.pop_back();
                }
                a.push_back(c);
            }
        }
    }
    if (a.size())
        ans.push_back(a.size());
    if (b.size())
        ans.push_back(b.size());
    
    cout << ans.size() << ' ' << *max_element(ans.begin(), ans.end());

    return 0;
}