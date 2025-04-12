#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c || b == a + 1 && c == b + 1)
        cout << "Yes\n";
    else 
        cout << "No\n";

    return 0;
}