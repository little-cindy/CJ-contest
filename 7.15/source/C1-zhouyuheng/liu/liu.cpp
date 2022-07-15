#include <bits/stdc++.h>

using namespace std; 

const int Maxn = 4e5 + 10; 

int n, m, k; 

int p[Maxn]; 

struct edge {
	int to, nxt; 
} e[Maxn];
int head[Maxn], tot; 

void add_edge(int x, int y) {
	++tot; 
	e[tot].to = y; 
	e[tot].nxt = head[x]; 
	head[x] = tot; 
} 

bool vis[Maxn]; 

int fa[Maxn], cnt; 

void init() {
	for (int i = 1; i <= n; ++i) fa[i] = i; 
	cnt = n; 
}

int find(int x) {
	if (fa[x] == x) return x; 
	return fa[x] = find(fa[x]); 
}

void merge(int x, int y) {
	int p = find(x), q = find(y); 
	if (p == q) return; 
	--cnt; 
	fa[p] = q; 
}

int ans[Maxn]; 

int main() {
	freopen("liu.in", "r", stdin); 
	freopen("liu.out", "w", stdout); 
	int i, j; 
	scanf("%d %d", &n, &m); 
	for (i = 1; i <= m; ++i) {
		int x, y; 
		scanf("%d %d", &x, &y); ++x, ++y; 
		add_edge(x, y), add_edge(y, x); 
	}
	for (i = 1; i <= n; ++i) vis[i] = 1; 
	scanf("%d", &k); 
	for (i = 1; i <= k; ++i) {
		scanf("%d", p + i); ++p[i]; 
		vis[p[i]] = 0; 
	}
	// 1 表示当前加入了的节点 
	init(); 
	for (i = 1; i <= n; ++i) if (vis[i]) 
		for (j = head[i]; j; j = e[j].nxt) 
			if (vis[e[j].to]) merge(i, e[j].to); 
	ans[k] = cnt - k; 
	for (i = k; i >= 1; --i) {
//		printf("%d\n", i);  
		vis[p[i]] = 1; 
		for (j = head[p[i]]; j; j = e[j].nxt) 
			if (vis[e[j].to]) merge(p[i], e[j].to); 
		ans[i - 1] = cnt - (i - 1); 
//		printf("#%d\n", cnt);  
	}
	for (i = 0; i <= k; ++i) 
		printf("%d\n", ans[i]); 
	return 0; 
} 
