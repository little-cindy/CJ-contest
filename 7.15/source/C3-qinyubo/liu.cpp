#include <bits/stdc++.h>
using namespace std;
namespace QYB {
    int n, m, k, cnt, f[400005], s[400005], a[400005];
    vector<int> g[400005]; bool vis[400005];
    int gf(int x) { return (x == f[x])? x: (f[x] = gf(f[x])); }
    bool merge(int x, int y) {
        x = gf(x); y = gf(y);
        if (x == y) return false;
        f[x] = y; return true;
    } int main() {
        freopen("liu.in", "r", stdin);
        freopen("liu.out", "w", stdout);
        scanf("%d%d", &n, &m);
        while (m--) {
            int u, v; scanf("%d%d", &u, &v); ++u; ++v;
            g[u].push_back(v); g[v].push_back(u);
        } scanf("%d", &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", s + i); ++s[i];
            vis[s[i]] = true;
        } for (int i = 1; i <= n; i++) f[i] = i;
        cnt = n - k;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) for (int j: g[i]) {
                if (!vis[j]) cnt -= merge(i, j);
            }
        } for (int i = k; i >= 1; i--) {
            a[i] = cnt++; vis[s[i]] = false;
            for (int j: g[s[i]]) {
                if (!vis[j]) cnt -= merge(s[i], j);
            }
        } a[0] = cnt;
        for (int i = 0; i <= k; i++) {
            printf("%d\n", a[i]);
        } return 0;
    }
} int main() {
    return QYB::main();
}