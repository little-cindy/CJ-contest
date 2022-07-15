#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

const int N = 1e5 + 10;
int n, p, Q, l, r, maxt, dp[N];

struct qwq {
  int pri, hap, t;
  inline bool operator <(const qwq &X) const {
    return t < X.t;
  }
} a[N];
vector <int> tim[N];
struct Query {
  int a, b, id, res;
  inline bool operator <(const Query &X) const {
    return a < X.a;
  }
} q[N];

inline bool cmp(Query x, Query y) {
  return x.id < y.id;
}

int main() {
  freopen("god.in", "r", stdin);
  freopen("god.out", "w", stdout);
  read(n), read(p);
  for (int i = 1; i <= n; ++i)
    read(a[i].pri), read(a[i].hap), read(a[i].t);
  sort(a + 1, a + 1 + n); l = 1, r = 1;
  for (int i = 1; i <= n; ++i) {
    tim[a[i].t].push_back(i);
    tim[a[i].t + p].push_back(-i);
  }
  read(Q);
  for (int i = 1; i <= Q; ++i)
    read(q[i].a), read(q[i].b), q[i].id = i, maxt = max(maxt, q[i].a);
  sort(q + 1, q + 1 + Q); int id = 1;
  for (int i = 1; i <= maxt; ++i) {
    for (auto ad: tim[i]) if (ad > 0) ++r; else ++l;
    if (q[id].a == i) {
      // cout << "TIME: " << i << " L: " << l << " R: " << r << endl;
      int maxcost = 0;
      for (int k = id; k <= Q && q[k].a == i; ++k)
        maxcost = max(maxcost, q[k].b);
      for (int k = 0; k <= maxcost; ++k) dp[k] = 0;
      for (int k = l; k <= r; ++k)
        for (int w = maxcost; w >= a[k].pri; --w)
          dp[w] = max(dp[w], dp[w - a[k].pri] + a[k].hap);
      for (int k = id; k <= Q && q[k].a == i; ++k)
        q[k].res = dp[q[k].b], id = max(id, k + 1);
    }
  }
  sort(q + 1, q + 1 + Q, cmp);
  for (int i = 1; i <= Q; ++i)
    printf("%d\n", q[i].res);
  return 0;
}