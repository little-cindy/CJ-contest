#include <bits/stdc++.h>
using namespace std;
int n, p, q, sum, ans;
struct node {
	int c, h, t;
}a[4005];
void dfs(int x, int d, int s, int v) {
	ans = max(ans, v);
	if(x > n || !s)
		return;
	if(a[x].t + p - 1 >= d && d >= a[x].t && s - a[x].c >= 0)
		dfs(x + 1, d, s - a[x].c, v + a[x].h);
	dfs(x + 1, d, s, v);
	return;
}
int main() {
	freopen("god.in", "r", stdin);
	freopen("god.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
		cin >> a[i].c >> a[i].h >> a[i].t, sum += a[i].h;
	cin >> q;
	if(pow(2, n) <= 1e8) {
		for(int x, y; q--;)
			ans = 0, cin >> x >> y, dfs(1, x, y, 0), cout << ans << '\n';
		return 0;
	}
	cout << sum;
	return 0;
}
