#include <bits/stdc++.h>
using namespace std;

const int N = 200;
map <int, int> qwq;
int cnt, n, m;
struct PAIR { int x, y; };
vector <PAIR> qaq[N*N];

inline bool cmpx(PAIR a, PAIR b) {
  return a.x < b.x;
}

inline bool cmpy(PAIR a, PAIR b) {
  return a.y < b.y;
}

int main() {
  freopen("sky.out", "r", stdin);
  cin >> n >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x; cin >> x;
      if (!qwq[x]) qwq[x] = ++cnt;
      qaq[qwq[x]].push_back({i, j});
    }
  for (int i = 1; i <= cnt; ++i) {
    sort(qaq[i].begin(), qaq[i].end(), cmpx);
    for (int j = 1; j < qaq[i].size(); ++j)
      if (qaq[i][j].x == qaq[i][j - 1].x)
        return !puts("Wrong Answer!");
    sort(qaq[i].begin(), qaq[i].end(), cmpy);
    for (int j = 1; j < qaq[i].size(); ++j)
      if (qaq[i][j].y == qaq[i][j - 1].y)
        return !puts("Wrong Answer!");
  }
  return !puts("Accepted!");
}