#include <bits/stdc++.h>
#define lc (p << 1 | 0)
#define rc (p << 1 | 1)
using namespace std;
namespace QYB {
    vector<pair<int, int> > f[80005], g[20005];
    int n, d, t, dp[25][4005], ans[20005];
    void insert(int p, int l, int r, int L, int R, int c, int h) {
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            f[p].push_back(make_pair(c, h));
            return;
        } int m = l + r >> 1;
        insert(lc, l, m, L, R, c, h);
        insert(rc, m + 1, r, L, R, c, h);
    } void dfs(int p, int l, int r, int dep) {
        for (int i = 0; i <= 4000; i++) dp[dep][i] = dp[dep - 1][i];
        for (auto i: f[p]) {
            for (int j = 4000; j >= i.first; j--) {
                dp[dep][j] = max(dp[dep][j], dp[dep][j - i.first] + i.second);
            }
        } if (l == r) {
            for (auto i: g[l]) ans[i.second] = dp[dep][i.first];
        } else {
            int m = l + r >> 1; dfs(lc, l, m, dep + 1); dfs(rc, m + 1, r, dep + 1);
        }
    } int main() {
        freopen("god.in", "r", stdin);
        freopen("god.out", "w", stdout);
        scanf("%d%d", &n, &d);
        while (n--) {
            int c, h, a; scanf("%d%d%d", &c, &h, &a);
            insert(1, 1, 20000, a, a + d - 1, c, h);
        } scanf("%d", &t);
        for (int i = 1; i <= t; i++) {
            int a, b; scanf("%d%d", &a, &b);
            g[a].push_back({b, i});
        } dfs(1, 1, 20000, 1);
        for (int i = 1; i <= t; i++) {
            printf("%d\n", ans[i]);
        } return 0;
    }
} int main() {
    return QYB::main();
}