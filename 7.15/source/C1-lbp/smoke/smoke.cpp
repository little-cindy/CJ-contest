#include <bits/stdc++.h>

using namespace std;

const int N = 5.5e5;

int n, v[N], val[N];
vector<int> g[N], sub[N];

void dfs(int u, int fa = 1) {
	sub[u] = {v[u]};
	for (int v : g[u]) if (v - fa) {
	  dfs(v, u);
	  for (int t : sub[v]) sub[u].emplace_back(t + 1);
	}
	for (int t : sub[u]) val[u] ^= t;
}

int main() {
	freopen("smoke.in", "r", stdin), freopen("smoke.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 2, x; i <= n; ++i) cin >> x, g[x].emplace_back(i), g[i].emplace_back(x);
  dfs(1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += val[i];
  return cout << ans << '\n', 0;
}

