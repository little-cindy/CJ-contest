#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
int n, tot, ans = -1, w, h, a[N], raw[N], cnt[N], sum[N];
vector<int> b[N];

void discrete() {
    memcpy(raw, a, sizeof(raw));
    sort(raw + 1, raw + n + 1);
    tot = unique(raw + 1, raw + n + 1) - raw - 1;

    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(raw + 1, raw + tot + 1, a[i]) - raw;
}

void add(int l, int r, int v, int d) {
    sum[l] += v, sum[l + 1] += d - v;
    sum[r + 1] -= v + d * (r - l + 1);
    sum[r + 2] += v + d * (r - l);
}

void init() {
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;

    for (int i = 1; i <= tot; i++) {
        add(1, cnt[i] - 1, 1, 1);
        add(cnt[i], n, cnt[i], 0);
    }

    for (int t = 1; t <= 2; t++)
        for (int i = 1; i <= n; i++)
            sum[i] += sum[i - 1];
}

void calc() {
    for (int i = n, j = 0; i >= 1; i--) {
        while (j < i && sum[j + 1] >= i * (j + 1))
            j++;

        if (i * j > ans)
            ans = i * j, w = i, h = j;
    }
}

void output() {
    for (int i = 1; i <= h; i++)
        b[i].resize(w + 1);

    int x = 1, y = 1, z = 1;

    for (int i = 1; i <= tot; i++) {
        int t = min({cnt[i], h, ans});
        ans -= t;

        while (t--) {
            b[x][y] = raw[i];

            if (x == h)
                x = 1, y = ++z;
            else
                x++, y = y % w + 1;
        }

        if (!ans)
            break;
    }
}

int main() {
    freopen("sky.in", "r", stdin);
    freopen("sky.out", "w", stdout);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    discrete(), init();
    calc(), output();
    printf("%d\n%d %d\n", ans, h, w);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            printf("%d ", b[i][j]);

        puts("");
    }

    return 0;
}
