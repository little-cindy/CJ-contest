#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;

const int N = 4e3 + 5, M = 2e4 + 5, M4 = M * 4, LOG = 20;
int n, p, q, c[N], h[N], b[M], ans[M], f[LOG][M];
vector<int> id1[M4], id2[M4];

void modify1(int p, int l, int r, int ml, int mr, int i) {
    if (ml <= l && mr >= r) {
        id1[p].emplace_back(i);
        return;
    }

    if (ml <= mid)
        modify1(ls, l, mid, ml, mr, i);

    if (mr > mid)
        modify1(rs, mid + 1, r, ml, mr, i);
}

void modify2(int p, int l, int r, int pos, int i) {
    if (l == r) {
        id2[p].emplace_back(i);
        return;
    }

    if (pos <= mid)
        modify2(ls, l, mid, pos, i);
    else
        modify2(rs, mid + 1, r, pos, i);
}

void solve(int p, int l, int r, int d) {
    for (int i = 0; i < M; i++)
        f[d][i] = f[d - 1][i];

    for (int i : id1[p])
        for (int j = M - 1; j >= c[i]; j--)
            f[d][j] = max(f[d][j], f[d][j - c[i]] + h[i]);

    if (l == r)
        for (int i : id2[p])
            ans[i] = f[d][b[i]];
    else
        solve(ls, l, mid, d + 1), solve(rs, mid + 1, r, d + 1);
}

int main() {
    freopen("god.in", "r", stdin);
    freopen("god.out", "w", stdout);
    scanf("%d%d", &n, &p);

    for (int i = 1, t; i <= n; i++) {
        scanf("%d%d%d", &c[i], &h[i], &t);
        modify1(1, 1, M, t, t + p - 1, i);
    }

    scanf("%d", &q);

    for (int i = 1, a; i <= q; i++) {
        scanf("%d%d", &a, &b[i]);
        modify2(1, 1, M, a, i);
    }

    solve(1, 1, M, 1);

    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);

    return 0;
}
