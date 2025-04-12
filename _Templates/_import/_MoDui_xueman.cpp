namespace MoDui
{
    struct query
    { // 查询区间为[l, r]，id表示是第几次查询
        int l, r, id;
    };
    ll belong[maxn], out[maxn];

    bool operator<(query a, query b)
    {
        if (belong[a.l] != belong[b.l])
            return belong[a.l] < belong[b.l];
        else if (belong[a.l] & 1)
            return a.r < b.r;
        else
            return a.r > b.r;
    }

    void work(int n, vector<query> q)
    {
        int size = sqrt(n);
        int number = ceil((double)n / size);
        for (int i = 1; i <= number; ++i)
        {
            for (int j = (i - 1) * size + 1; j <= i * size; ++j)
                belong[j] = i;
        }
        sort(q.begin(), q.end());
        int l = 1, r = 0;
        for (auto item : q)
        {

            // cout << ans << ' ';

            while (l < item.l)
            {
                ans -= max(r - suf[l] + 1, 0ll);
                l++;
            }
            // cout << ans << ' ';

            while (l > item.l)
            {
                l--;
                ans += max(r - suf[l] + 1, 0ll);
            }
            // cout << ans << ' ';

            while (r < item.r)
            {
                r++;
                ans += max(pre[r] - l + 1, 0ll);
            }
            // cout << ans << ' ';

            while (r > item.r)
            {
                ans -= max(pre[r] - l + 1, 0ll);
                r--;
            }
            // cout << ans << endl;

            out[item.id] = ans;
        }
    }
};

