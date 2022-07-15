#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &x) {
  x = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

const int N = 4e5 + 10;
int n, MAX, cnt, a[N], val[N], num[N];
struct SET {
  int val, id;
  SET(int val, int id): val(val), id(id) {}
  SET() {}
  bool operator <(const SET &X) const {
    return val > X.val;
  }
} p[N];

int cursiz, Col, Lin;
vector <int> res[700];

int main() {
  freopen("sky.in", "r", stdin);
  freopen("sky.out", "w", stdout);
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1]) a[i] = cnt;
    else val[++cnt] = a[i], a[i] = cnt;
  }
  for (int i = 1; i <= n; ++i) ++num[a[i]];
  for (int i = 1; i <= cnt; ++i) p[i] = SET(num[i], i);
  sort(p + 1, p + 1 + cnt); int cur = 2, per = 1, sum = n;
  for (int i = p[1].val; i; --i) {
    while (i == p[cur].val && cur <= cnt) ++cur, ++per;
    int col = i, lin = sum / col;
    if (col > lin) { sum -= per; continue; }
    if (col * lin <= cursiz) { sum -= per; continue; }
    cursiz = col * lin, Col = col, Lin = lin;
  }
  for (int i = 1; i <= Col; ++i)
    for (int j = 1; j <= Lin + 10; ++j) res[i].push_back(0);
  int toid = 1, x = 1, y = 1, tot = 0;
  printf("%d\n%d %d\n", cursiz, Col, Lin);
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 1; j <= min(p[i].val, Col); ++j) {
      res[x][y - 1] = p[i].id, ++tot;
      if (tot == cursiz) break;
      ++x, ++y;
      if (x > Col) x = 1, y = ++toid;
      if (y > Lin) y = 1;
    }
    if (tot == cursiz) break;
  }
  for (int i = 1; i <= Col; ++i) {
    for (int j = 0; j < Lin; ++j)
      printf("%d ", val[res[i][j]]);
    puts("");
  }
  return 0;
}