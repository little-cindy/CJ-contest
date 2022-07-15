#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n, m, k, fa[N], ans[N], cnt, del[N];
vector<int> g[N]; 
bool vis[N];

int get(int x) { return x - fa[x] ? fa[x] = get(fa[x]) : x; }
inline void mer(int x, int y) { x = get(x), y = get(y), fa[x] = y; }

int main() {
	freopen("liu.in", "r", stdin), freopen("liu.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
  cin >> k;
  for (int i = 1; i <= k; ++i) cin >> del[i], vis[del[i]] = 1;
  iota(fa, fa + n, 0);
  for (int i = 0; i < n; ++i) if (!vis[i]) for (int j : g[i]) if (!vis[j]) mer(i, j); 
  for (int i = 0; i < n; ++i) cnt += ((get(i) == i) && (!vis[i]));
  int x = cnt;
  for (int i = k; i; --i) {
    set<int> s;
    int u = del[i];
  	for (int v : g[u]) if (!vis[v]) s.insert(get(v));
  	if (s.size() == 0) {
		  ans[i] = (++cnt);
		  continue;
		}
    int x = *s.begin();
  	vis[u] = 0, ans[i] = (cnt -= (int)s.size() - 1), s.erase(s.begin());
  	for (int t : s) mer(t, x);
  	mer(u, x);
	}
	for (int i = 1; i <= k; ++i) cout << ans[i] << '\n';
  return cout << x << '\n', 0;
}
