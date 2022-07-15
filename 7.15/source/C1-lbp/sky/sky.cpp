#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 4e5 + 5;

int n, a[N], ansx, ansy, val[N], m;
vector<int> v, w[N];

signed main() {
	freopen("sky.in", "r", stdin), freopen("sky.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], v.emplace_back(a[i]);
  sort(begin(v), end(v)), v.erase(unique(begin(v), end(v)), end(v)), m = v.size();
  for (int i = 1; i <= n; ++i) ++val[a[i] = lower_bound(begin(v), end(v), a[i]) - begin(v) + 1];
  sort(val + 1, val + m + 1);
  int x = 1, sum = 0;
  for (int i = 1; i * i <= n; ++i) {
  	int r = 0;
    while (x <= m && val[x] <= i) sum += val[x], ++x;
    r = sum + (m - x + 1) * i;
    if (r / i >= i && r / i * i >= ansx * ansy) ansx = i, ansy = r / i;
	}
	cout << ansx * ansy << '\n' << ansx << ' ' << ansy << '\n';
	for (int i = 1; i <= m; ++i) val[i] = min(val[i], ansx);
	sort(val + 1, val + m + 1, greater<int>());
	int y = ansy, t, cur = 0;
	x = ansx;
	for (int i = 0; i < y; ++i) w[i].resize(x);
	for (int i = 1; i <= m; ++i) {
		if (t + val[i] < x) {
			for (int j = t; j < t + val[i]; ++j) w[cur][j] = i;
			t += val[i];
		} else {
			for (int j = t; j < x; ++j) w[cur][j] = i, --val[i];
			++cur, t = 0;
			for (int j = t; j < t + val[i]; ++j) w[cur][j] = i;
		}
	}
	for (int i = 0; i < x; ++i, cout << '\n') for (int j = 0; j < y; ++j) cout << w[i][(i + j) % y] << ' ';
  return 0;
}
