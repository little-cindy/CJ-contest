#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int fa[N], ask[N], ans[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool Union(int x, int y) { x = find(x), y = find(y); if(x == y) return 0; fa[x] = y; return 1;}
vector <int> v[N];
bool vis[N];

signed main(){
	freopen("liu.in", "r", stdin);
	freopen("liu.out", "w", stdout);
	int n, m, q; scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y; 
		scanf("%lld%lld", &x, &y); x++, y++;
		v[x].push_back(y); v[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	scanf("%lld", &q);
	for(int i = 1; i <= q; i++){
		int x; scanf("%lld", &x); x++;
		ask[i] = x; vis[x] = true;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == true) continue;
		for(int j = 0; j < v[i].size(); j++){
			if(vis[v[i][j]] == true) continue;
			Union(i, v[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(vis[i] == true) continue;
		if(fa[i] == i) ans[q]++;
	}
	
	for(int i = q; i >= 1; i--){
		int x = ask[i];
		ans[i - 1] = ans[i] + 1;
		for(int j = 0; j < v[x].size(); j++){
			if(vis[v[x][j]] == true) continue;
			//printf("%d<->%d\n", x, v[x][j]);
			ans[i - 1] -= Union(v[x][j], x);
		}
		vis[x] = false;
	}
	for(int i = 0; i <= q; i++)
		printf("%lld\n", ans[i]);
} 
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7	
*/
