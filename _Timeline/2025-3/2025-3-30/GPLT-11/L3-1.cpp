#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct edge
{
	int v, w;	
};

vector<edge> g1[100005];
vector<edge> g2[100005];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		g1[u].push_back({v, c});
		g2[v].push_back({u, d});
	}
	
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	vector<i64> d1(n + 1, 1e18);
	vector<i64> d2(n + 1, 1e18);
	vector<int> vis1(n + 1);
	vector<int> vis2(n + 1);
	
	auto dij = [&](vector<i64> &d, int s, vector<edge> g[], vector<int> &vis)
	{
		priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> q;
		d[s] = 0;
		q.push({0, s});
		while (q.size())
		{
			i64 dis = q.top().first;
			int x = q.top().second;
			q.pop();
			if (vis[x])
				continue;
			vis[x] = 1;
			for (auto &e : g[x])
			{
				int v = e.v, w = e.w;
				if (d[v] > d[x] + w)
				{
					d[v] = d[x] + w;
					q.push({d[v], v});
				}
			}
		}
	};
	
	dij(d1, 1, g1, vis1);
	dij(d2, n, g2, vis2);
	vector<i64> res(n + 1);
	multiset<i64> ss;
	for (int i = 1; i <= n; i++)
	{
		if (vis1[i] && vis2[i])
		{
			res[i] = d1[i] + (d2[i] + a[i] - 1) / a[i];
			ss.insert(res[i]);
		}
	}
	ss.insert(d1[n]);
	ss.insert(d2[1]);
	while (q--)
	{
		int i, d;
		cin >> i >> d;
		if (vis1[i] && vis2[i])
		{
			a[i] = d;
			auto it = ss.find(res[i]);
			ss.erase(it);
			res[i] = d1[i] + (d2[i] + a[i] - 1) / a[i];
			ss.insert(res[i]);
		}
		cout << *ss.begin() << '\n';
	}
	
	return 0;
} 
