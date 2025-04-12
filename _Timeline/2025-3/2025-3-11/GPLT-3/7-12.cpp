#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    a[0] = -100000;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int t = i;
        while (t > 1 && a[t] < a[t / 2])
        {
            swap(a[t], a[t / 2]);
            t = t / 2;
        }
    }
    
    auto find = [&](int x) -> int
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == x)
                return i;
        }
        return 0;
    };

    cin.ignore(80, '\n');
    while (q--)
    {
        string s, t;
        getline(cin, s);
        stringstream ss;
        ss << s;
        int fl = 0;
        vector<string> vec;
        while (ss >> t)
        {
            vec.push_back(t);
            if (t == "root")
            {
                fl = 1;
            }
            else if (t == "siblings")
            {
                fl = 2;
            }
            else if (t == "parent")
            {
                fl = 3;
            }
            else if (t == "child")
            {
                fl = 4;
            }
        }
        if (fl == 1)
        {
            int k = stoi(vec.front());
            cout << (a[1] == k ? "T" : "F") << '\n';
        }
        else if (fl == 2)
        {
            int k1 = stoi(vec[0]), k2 = stoi(vec[2]);
            if (k1 == a[0] || k2 == a[0])
            {
                cout << "F" << '\n';
            }
            else 
            {
                if ((find(k1) >> 1 << 1) == (find(k2) >> 1 << 1))
                {
                    cout << "T\n";
                }
                else
                {
                    cout << "F\n";
                }
            }
        }
        else if (fl == 3)
        {
            int k1 = stoi(vec[0]), k2 = stoi(vec.back());
            if (find(k1) == (find(k2) >> 1))
            {
                cout << "T\n";
            }
            else 
            {
                cout << "F\n";
            }
        }
        else if (fl == 4)
        {
            int k2 = stoi(vec[0]), k1 = stoi(vec.back());
            if (find(k1) == (find(k2) >> 1))
            {
                cout << "T\n";
            }
            else 
            {
                cout << "F\n";
            }
        }
    }
    

    return 0;
}