#include <bits/stdc++.h>
using namespace std;
namespace QYB {
    int n, a[400005];
    int main() {
        freopen("sky.in", "r", stdin);
        freopen("sky.out", "w", stdout);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        printf("%d\n%d %d\n", n, 1, n);
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
        return 0;
    }
} int main() {
    return QYB::main();
}