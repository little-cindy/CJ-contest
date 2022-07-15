#include <bits/stdc++.h>
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
const int maxn = 4e5 + 5;
int fa[maxn];
vector <int> vec[maxn];
struct node
{
	int id, next;
} edge[maxn << 1];
int head[maxn], len;
void add(int from, int to)
{
	edge[++len].id = to;
	edge[len].next = head[from];
	head[from] = len;
}
int find(int x)
{
	return fa[x] != x ? fa[x] = find(fa[x]) : x;
}
int de[maxn], ans[maxn];
bool flag[maxn], flag2[maxn];
void dfs(int now)
{
	flag2[now] = 1;
	for (int i = head[now]; i; i = edge[i].next)
		if (!flag[edge[i].id] && !flag2[edge[i].id])
			dfs(edge[i].id);
}
signed main()
{
	freopen("liu.in", "r", stdin);
	freopen("liu.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		x++, y++;
		if (x != y)
			vec[x].push_back(y), vec[y].push_back(x), add(x, y), add(y, x);
	}
	int k = read();
	for (int i = 1; i <= k; i++)
	{
		de[i] = read();
		de[i]++;
		flag[de[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!flag[i])
		{
			for (int j: vec[i])
				if (!flag[j])
					fa[find(i)] = find(j);
		}
	int nowans = 0;
	for (int i = 1; i <= n; i++)
		if (!flag[i] && !flag2[i])
			nowans++, dfs(i);
	ans[k] = nowans;
	for (int i = k; i >= 1; i--)
	{
		int tmp = de[i];
		flag[tmp] = 0; 
		nowans++;
		for (int j: vec[tmp])
			if (!flag[j])
				if (find(tmp) != find(j))
					fa[find(tmp)] = find(j), nowans--;
		ans[i - 1] = nowans;
	}
	for (int i = 0; i <= k; i++)
		printf("%d\n", ans[i]);
	return 0;
}
