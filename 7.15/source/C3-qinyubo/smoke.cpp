#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace QYB {
    int n; ll ans, v[600005]; vector<int> g[600005];
    ll calc(int cur, ll d) {
        ll res = v[cur] + d;
        for (int i: g[cur]) {
            res ^= calc(i, d + 1);
        } return res;
    } void dfs(int cur) {
        ans += calc(cur, 0);
        for (int i: g[cur]) dfs(i);
    } int main() {
        freopen("smoke.in", "r", stdin);
        freopen("smoke.out", "w", stdout);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", v + i);
        for (int i = 2, f; i <= n; g[f].push_back(i++)) scanf("%d", &f);
        dfs(1); return !printf("%lld\n", ans);
    }
} int main() {
    return QYB::main();
}