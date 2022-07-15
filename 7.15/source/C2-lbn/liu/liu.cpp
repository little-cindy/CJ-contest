#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;
vector <int> G[N]; bool des[N];
int n, m, k, d[N], res[N], fa[N], siz[N];

template <typename T> inline void read(T &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

inline int getf(int x) { return fa[x] == x? x : fa[x] = getf(fa[x]); }

int main() {
  freopen("liu.in", "r", stdin);
  freopen("liu.out", "w", stdout);
  read(n), read(m);
  for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= m; ++i) {
    int u, v; read(u), read(v); ++u, ++v;
    if (u == v) continue;
    G[u].push_back(v), G[v].push_back(u);
  }
  read(k);
  for (int i = 1; i <= k; ++i)
    read(d[i]), ++d[i], des[d[i]] = true, siz[d[i]] = 0;
  for (int i = 1; i <= n; ++i) {
    if (des[i]) continue;
    for (auto to: G[i]) {
      if (des[to]) continue;
      int fx = getf(i), fy = getf(to);
      if (fx == fy) continue;
      fa[fx] = fy, siz[fy] += siz[fx], siz[fx] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) if (siz[i]) ++res[k];
  for (int i = k - 1; ~i; --i) {
    res[i] = res[i + 1], des[d[k + 1]] = false, ++res[i];
    for (auto to: G[d[i + 1]]) {
      if (des[to]) continue;
      int fx = getf(d[i + 1]), fy = getf(to);
      if (fx == fy) continue;
      --res[i], fa[fx] = fy, siz[fy] += siz[fx], siz[fx] = 0;
    }
  }
  for (int i = 0; i <= k; ++i) printf("%d\n", res[i]);
  return 0;
}