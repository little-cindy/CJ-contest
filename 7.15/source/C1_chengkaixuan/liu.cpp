#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, k, id[N], fa[N], ans[N];
bool vis[N];
vector<int> g[N];

int getRoot(int x) {
    return x == fa[x] ? x : fa[x] = getRoot(fa[x]);
}

int merge(int x, int y) {
    x = getRoot(x), y = getRoot(y), fa[x] = y;
    return x != y;
}

int main() {
    freopen("liu.in", "r", stdin);
    freopen("liu.out", "w", stdout);
    scanf("%d%d", &n, &m);

    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y), x++, y++;
        g[x].emplace_back(y), g[y].emplace_back(x);
    }

    scanf("%d", &k);

    for (int i = 1; i <= k; i++)
        scanf("%d", &id[i]), id[i]++, vis[id[i]] = true;

    iota(fa + 1, fa + n + 1, 1);
    int res = n - k;

    for (int i = 1; i <= n; i++)
        for (int j : g[i])
            if (!vis[i] && !vis[j])
                res -= merge(i, j);

    for (int i = k; i >= 0; i--) {
        ans[i] = res, res++, vis[id[i]] = false;

        for (int j : g[id[i]])
            if (!vis[j])
                res -= merge(id[i], j);
    }

    for (int i = 0; i <= k; i++)
        printf("%d\n", ans[i]);

    return 0;
}
