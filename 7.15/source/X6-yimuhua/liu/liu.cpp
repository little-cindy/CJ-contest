#include <bits/stdc++.h>
using namespace std;
bool vis[1000005];
int n, m, k, cnt, tot, b[1000005], fa[1000005], head[1000005], ans[1000005];
struct node {
	int x, y, nxt;
}a[1000005];
void add(int x, int y) {
	a[++tot] = (node){x, y, head[x]}, head[x] = tot;
	return;
}
int find(int x) {
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
int main() {
	freopen("liu.in", "r", stdin);
	freopen("liu.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n; i++)
		fa[i] = i;
	for(int i = 1, x, y; i <= m; i++)
		cin >> x >> y, add(x, y), add(y, x);
	cin >> k, cnt = n - k;
	for(int i = 1, x; i <= k; i++)
		cin >> x, vis[x] = 1, b[i] = x;
	for(int i = 1; i <= tot; i++)
		if(!vis[a[i].x] && !vis[a[i].y] && fa[find(a[i].x)] != fa[find(a[i].y)])
			cnt--, fa[find(a[i].x)] = fa[find(a[i].y)];
	ans[k + 1] = cnt;
	for(int i = k; i; i--) {
		cnt++, vis[b[i]] = 0;
		for(int j = head[b[i]]; j; j = a[j].nxt)
			if(!vis[a[j].y] && fa[find(b[i])] != fa[find(a[j].y)])
				cnt--, fa[find(b[i])] = fa[find(a[j].y)];
		ans[i] = cnt;
	}
	for(int i = 1; i < k + 2; i++)
		cout << ans[i] << '\n';
	return 0;
}
