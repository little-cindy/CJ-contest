#include <bits/stdc++.h>

using namespace std; 

const int Maxn = 4e3 + 10; 
const int Maxd = 2e4 + 10; 

int n, p, q; 

vector<pair<int, int> > tree[Maxd << 2]; 

inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }

void update(int now, int l, int r, int L, int R, pair<int, int> p) {
	if (L <= l && r <= R) {
		tree[now].emplace_back(p); 
		return; 
	}
	int mid = l + r >> 1; 
	if (L <= mid) update(ls(now), l, mid, L, R, p); 
	if (R > mid) update(rs(now), mid + 1, r, L, R, p); 
}

int f[Maxn]; 
vector<pair<int, int> > query[Maxd]; 
int ans[Maxd]; 

void dfs(int now, int l, int r) {
	int i, j; 
	int t[Maxn]; 
	for (i = 0; i <= 4e3; ++i) t[i] = f[i]; 
	for (i = 0; i < tree[now].size(); ++i) 
		for (j = 4e3; j >= 0; --j) if (j + tree[now][i].first <= 4e3) 
			f[j + tree[now][i].first] = max(f[j + tree[now][i].first], f[j] + tree[now][i].second); 		
	if (l == r) {
		for (i = 0; i < query[l].size(); ++i) 
			ans[query[l][i].second] = f[query[l][i].first]; 
		for (i = 0; i <= 4e3; ++i) f[i] = t[i]; 
		return; 
	}
	int mid = l + r >> 1; 
	dfs(ls(now), l, mid), dfs(rs(now), mid + 1, r); 
	for (i = 0; i <= 4e3; ++i) f[i] = t[i]; 
} 

int main() {
	freopen("god.in", "r", stdin); 
	freopen("god.out", "w", stdout); 
	int i, j; 
	scanf("%d %d", &n, &p); 
	for (i = 1; i <= n; ++i) {
		int c, h, t; 
		scanf("%d %d %d", &c, &h, &t); 
		update(1, 1, 2e4, t, t + p - 1, make_pair(c, h)); 
	}
	scanf("%d", &q); 
	for (i = 1; i <= q; ++i) {
		int a, b; 
		scanf("%d %d", &a, &b); 
		query[a].emplace_back(b, i); 
	}
	dfs(1, 1, 2e4); 
	for (i = 1; i <= q; ++i) 
		printf("%d\n", ans[i]); 
	return 0; 
}
