#include <bits/stdc++.h>
using namespace std;
vector<int> v[530005];
int n, ans, a[530005], b[530005];
int dfs(int x) {
	int s = a[x];
	for(int i = 0; i < v[x].size(); i++)
		s ^= dfs(v[x][i]);
	return b[x] = s;
}
void f(int x, int s, int y) {
	b[x] ^= a[y] + s;
	for(int i = 0; i < v[x].size(); i++)
		f(v[x][i], s + 1, y);
	return;
}
int main() {
	freopen("smoke.in", "r", stdin);
	freopen("smoke.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n * n <= 1e8) {
		for(int i = 2, x; i <= n; i++)
			cin >> x, v[i].push_back(x);
		for(int i = 1; i <= n; i++)
			f(i, 0, i);
		for(int i = 1; i <= n; i++)
			ans += b[i];
		cout << ans;
		return 0;
	}
	for(int i = 2, x; i <= n; i++)
		cin >> x, v[x].push_back(i);
	dfs(1);
	for(int i = 1; i <= n; i++)
		ans += b[i];
	cout << ans;
	return 0;
}
