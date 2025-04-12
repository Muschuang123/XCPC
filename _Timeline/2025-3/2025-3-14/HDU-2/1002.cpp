#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> a = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
vector<string> b = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    int i = 0, j = 0;
    while (1)
    {
        if (cnt >= 60)
            break;
        if (a[i] + b[j] == s)
        {
            cout << cnt + 1984 << '\n';
        }
        i++, j++;
        if (i >= 10)
            i = 0;
        if (j >= 12)
            j = 0;
        cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}