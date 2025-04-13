#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    int ans = 0;
    for (auto c : s)
    {
        if (islower(c))
            ans++;
    }
    cout << ans << endl;
}