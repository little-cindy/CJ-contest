#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 525015, B = 22, M = N * B;
int n, tot, rt, v[N], ch[M][2], sum[M], siz[M];

void pushUp(int p, int b) {
    sum[p] = sum[ch[p][0]] + sum[ch[p][1]];

    if (siz[ch[p][1]] & 1)
        sum[p] += 1 << b;
}

void add(int p, int b) {
    if (b == B)
        return;

    swap(ch[p][0], ch[p][1]);
    add(ch[p][0], b + 1);
    pushUp(p, b);
}

void insert(int p, int v, int b) {
    siz[p]++;

    if (b == B)
        return;

    int f = v >> b & 1;

    if (!ch[p][f])
        ch[p][f] = ++tot;

    insert(ch[p][f], v, b + 1);
    pushUp(p, b);
}

int main() {
    freopen("smoke.in", "r", stdin);
    freopen("smoke.out", "w", stdout);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    rt = ++tot;
    ll ans = 0;

    for (int i = n; i >= 1; i--) {
        add(rt, 0);
        insert(rt, v[i], 0);
        ans += sum[rt];
    }

    printf("%lld\n", ans);
    return 0;
}
