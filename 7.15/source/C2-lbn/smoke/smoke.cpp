#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T> inline void read(T &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

const int N = 5.3e5 + 10;
int n, v[N], val[N]; vector <int> G[N];

inline void DFS(int st, int cur, int far) {
  val[st] ^= (v[cur] + far);
  for (auto to: G[cur]) DFS(st, to, far + 1); return ;
}

signed main() {
  freopen("smoke.in", "r", stdin);
  freopen("smoke.out", "w", stdout);
  read(n); int f;
  for (int i = 1; i <= n; ++i) read(v[i]);
  for (int i = 2; i <= n; ++i)
    read(f), G[f].push_back(i);
  for (int i = 1; i <= n; ++i) DFS(i, i, 0);
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += val[i];
  printf("%lld\n", sum);
  return 0;
}