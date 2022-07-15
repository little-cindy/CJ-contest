#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int sum = 0, ne = 1;
	char ch = getchar();
	for (; (ch < '0' || ch > '9') && ch != '-'; ch = getchar());
	if (ch == '-') ne = -1, ch = getchar();
	for (; (ch >= '0' && ch <= '9'); ch = getchar())
		sum = (sum << 3) + (sum << 1) + (ch ^ 48);
	return sum * ne;
}
const int maxn = 6e5 + 5;
struct node
{
	int id, next;
} edge[maxn << 1];
int len, head[maxn];
void add(int from, int to)
{
	edge[++len].id = to;
	edge[len].next = head[from];
	head[from] = len;
}
int dep[maxn], tmpans, v[maxn];
void solve(int now, int fa, int gen)
{
	tmpans = tmpans ^ (v[now] + dep[now] - dep[gen]);
	for (int i = head[now]; i; i = edge[i].next)
		if (edge[i].id != fa)
			solve(edge[i].id, now, gen);
}
void dfs(int now, int fa)
{
	dep[now] = dep[fa] + 1;
	for (int i = head[now]; i; i = edge[i].next)
		if (edge[i].id != fa)
			dfs(edge[i].id, now);
}
int fa[maxn];
signed main()
{
	freopen("smoke.in", "r", stdin);
	freopen("smoke.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
		v[i] = read();
	for (int i = 2; i <= n; i++)
	{
		int tmp = read();
		add(tmp, i);
		add(i, tmp);
		fa[i] = tmp;
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		tmpans = 0;
		solve(i, fa[i], i);
		ans += tmpans;
	}
	printf("%lld", ans);
	return 0;
}

