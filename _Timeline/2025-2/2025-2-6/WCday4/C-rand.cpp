#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    srand(354698);

    int t = rand() % 6 + 1;
    cout << t << '\n';
    while (t--)
    {
        int n = rand() % 10 + 1;
        cout << n << '\n';
        for (int i = 0; i < n; i++)
        {
            int c = rand() % 3;
            if (c == 0)
                cout << '?';
            if (c == 1)
                cout << '1';
            if (c == 2)
                cout << '0';
        }
        cout << '\n';
    }
    

    return 0;
}