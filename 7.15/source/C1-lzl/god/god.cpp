#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 2e4 + 1005;
struct node{
	int c, h, l, r;
};

vector<pair<int, int> > tree[N << 1];
int T[N];
bool T2[N];

vector<int> v[N];
vector<int> id[N];

int n, p;

void insert(int cur, int l, int r, node x){
	if(l >= x.l and r <= x.r){
		tree[cur].emplace_back(x.c, x.h);
		T2[cur] = true;
		return;
	}
	int mid = (l + r) >> 1;
	if(x.l <= mid) insert(cur << 1, l, mid, x); 
	if(x.r > mid) insert(cur << 1 | 1, mid + 1, r, x);
	if(T2[cur << 1] == true or T2[cur << 1 | 1] == true) T2[cur] = true; 
}

int f[M << 2], sum[N];

vector<pair<int, int> >now;

void dfs(int cur, int l, int r){
	if(T[cur] == 0) return;
	if(T2[cur] == false){
		int maxi = 0;
		for(int i = l; i <= r; i++){
			if(v[i].size() == 0) continue;
			for(int j = 0; j < v[i].size(); j++) maxi = max(maxi, v[i][j]);
		}
		memset(f, 0, sizeof(f));
		for(int i = 0; i < now.size(); i++){
			int w = now[i].second, c = now[i].first;
			for(int j = maxi; j >= c; j--) f[j] = max(f[j], f[j - c] + w);
		} 
		for(int i = l; i <= r; i++){
			if(v[i].size() == 0) continue;
			for(int j = 0; j < v[i].size(); j++){
				sum[id[i][j]] = f[v[i][j]];
			}
		}
		return;
	}
	if(l == r){
		//if(v[l].size() == 0) return;
		for(int i = 0; i < tree[cur].size(); i++)
			now.emplace_back(tree[cur][i]);
		int maxi = 0;
		memset(f, 0, sizeof(f));
		for(int i = 0; i < v[l].size(); i++) maxi = max(maxi, v[l][i]);
		for(int i = 0; i < now.size(); i++){
			int w = now[i].second, c = now[i].first;
			for(int j = maxi; j >= c; j--){
				f[j] = max(f[j], f[j - c] + w);
			}
		} 
		for(int i = 0; i < v[l].size(); i++){
			sum[id[l][i]] = f[v[l][i]];
		}
		for(int i = tree[cur].size() - 1; i >= 0; i--) now.pop_back();
		return;
	}
	for(int i = 0; i < tree[cur].size(); i++)
		now.emplace_back(tree[cur][i]);
	int mid = (l + r) >> 1;
	dfs(cur << 1, l, mid), dfs(cur << 1 | 1, mid + 1, r);
	for(int i = tree[cur].size() - 1; i >= 0; i--) now.pop_back();
	return;
}

void pushup(int cur){
	T[cur] = T[cur << 1] + T[cur << 1 | 1];
}

void build(int cur, int l, int r){
	if(l == r){
		T[cur] = v[l].size();
		return;
	}
	int mid = (l + r) >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	pushup(cur);
}

int main(){
	freopen("god.in", "r", stdin);
	freopen("god.out", "w", stdout);
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++) {
		node x;
		scanf("%d%d%d", &x.c, &x.h, &x.l); x.r = min(x.l + p - 1, M);
		insert(1, 1, M * 2, x);
	}
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		int a, b; scanf("%d%d", &a, &b);
		v[a].push_back(b); id[a].push_back(i);
	}
	build(1, 1, M * 2);
	dfs(1, 1, M * 2);
	for(int i = 1; i <= q; i++){
		printf("%d\n", sum[i]);
	}
}

/*
4 4
2 3 2
3 5 1
4 7 2
11 15 5
4
1 3
2 5
2 6
5 14
*/

