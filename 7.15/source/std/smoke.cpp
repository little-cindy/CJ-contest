#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
const int N = 1e6 + 500;
typedef long long ll;
using namespace std;

int n, head[N], cnte, val[N], cnt, rt[N], v[N];
struct edge { int to, nxt; } e[N << 1];
struct node { int cnt, ch[2]; } t[N << 5];
ll ans;

template < typename T >
inline T read()
{
	 T x = 0, w = 1; char c = getchar();
	 while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	 while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	 return x * w; 
}

inline void adde(int u, int v) { e[++cnte] = (edge) { v, head[u] }, head[u] = cnte; }

int merge(int x, int y)
{
	 if(!x || !y) return x + y;
	 t[x].cnt += t[y].cnt;
	 t[x].ch[0] = merge(t[x].ch[0], t[y].ch[0]);
	 t[x].ch[1] = merge(t[x].ch[1], t[y].ch[1]);
	 return x;
}

void add(int u, int &x)
{
	 for(int i = 0; i <= 21; i++)
	 {
		  if(t[t[u].ch[0]].cnt & 1) x ^= (1 << i);
		  if(t[t[u].ch[1]].cnt & 1) x ^= (1 << i);
		  swap(t[u].ch[0], t[u].ch[1]), u = t[u].ch[0];
	 }
}

void insert(int u, int v, int &x)
{
	 for(int op, i = 0; i <= 21; i++)
	 {
		  op = (v >> i) & 1, t[u].cnt++;
		  if(op) x ^= (1 << i);
		  if(!t[u].ch[op]) t[u].ch[op] = ++cnt;
		  u = t[u].ch[op];
	 }
}

void dfs(int u)
{
	 for(int v, i = head[u]; i; i = e[i].nxt)
	 {
		  v = e[i].to, dfs(v);
		  add(rt[v], val[v]), val[u] ^= val[v];
		  rt[u] = merge(rt[u], rt[v]);
	 }
	 insert(rt[u], v[u], val[u]);
	 ans += val[u];
}

int main()
{
	freopen("smoke.in", "r", stdin);
	freopen("smoke.out", "w", stdout);
	 n = read <int> ();
	 for(int i = 1; i <= n; i++) v[i] = read <int> ();
	 for(int i = 1; i <= n; i++) rt[i] = ++cnt;
	 for(int x, i = 2; i <= n; i++) x = read <int> (), adde(x, i); 
	 dfs(1);
	 printf("%lld\n", ans);
	 return 0; 
}
