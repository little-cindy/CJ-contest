#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 5, M = 2e4 + 5;

int n, p, q, f[M][N], g[N];
struct nod {
	int c, h, t;
} a[N];
vector<array<int, 2>> t[M << 2];

void ins(int o, nod a, int l, int r) {
	int L = a.t, R = a.t + p - 1, mid = l + r >> 1;
	if (L <= l && r <= R) return t[o].emplace_back(array<int, 2>{a.c, a.h}), void();
	if (l > R || L > r) return;
	ins(o * 2, a, l, mid), ins(o * 2 + 1, a, mid + 1, r);
}
void dfs(int o, int l = 1, int r = M - 1) {
	if (!t[o].size()) {
		int mid = l + r >> 1;
		if (l == r) for (int i = 0; i < N; ++i) f[l][i] = g[i];
		else dfs(o * 2, l, mid), dfs(o * 2 + 1, mid + 1, r);
		return;
	}
	vector<int> h(N);
	for (int i = 0; i < N; ++i) h[i] = g[i];
	for (auto a : t[o])
		for (int i = N - 1; i >= a[0]; --i) g[i] = max(g[i], g[i - a[0]] + a[1]);
	int mid = l + r >> 1;
  if (l == r) for (int i = 0; i < N; ++i) f[l][i] = g[i];
	else dfs(o * 2, l, mid), dfs(o * 2 + 1, mid + 1, r);
	for (int i = 0; i < N; ++i) g[i] = h[i];
}

int main() {
	freopen("god.in", "r", stdin), freopen("god.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) cin >> a[i].c >> a[i].h >> a[i].t, ins(1, a[i], 1, M - 1);
  dfs(1), cin >> q;
  while (q--) {
  	int a, b;
  	cin >> a >> b;
  	cout << f[a][b] << '\n';
	}
	return 0;
}

