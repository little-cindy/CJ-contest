#include <bits/stdc++.h>
#define int long long
#define lson (p << 1)
#define rson (p << 1 | 1)
using namespace std;
int read()
{
	int sum = 0, ne = 1;
	char ch = getchar();
	for (; (ch < '0' || ch > '9') && ch != '-'; ch = getchar());
	if (ch == '-') ne = -1, ch = getchar();
	for (; (ch >= '0' && ch <= '9'); ch = getchar())
		sum = (sum << 3) + (sum << 1) + (ch ^ 48);
	return sum * ne;
}
const int maxn = 5e4 + 5, maxq = 2e4 + 5;
struct node
{
	int l, r;
	vector <pair <int, int> > vec;
} tree[maxn << 2];
void build(int p, int l, int r)
{
	tree[p].l = l, tree[p].r = r;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
void update(int p, int l, int r, int x, int y)
{
	if (tree[p].l >= l && tree[p].r <= r)
	{
		tree[p].vec.push_back(make_pair(x, y));
		return;
	}
	int mid = tree[p].l + tree[p].r >> 1;
	if (l <= mid)
		update(lson, l, r, x, y);
	if (r > mid)
		update(rson, l, r, x, y);
}
int aska, askb;
vector <pair <int, int> > vec;
void solve(int p, int x)
{
	for (auto i: tree[p].vec)
		vec.push_back(i);
	if (tree[p].l == tree[p].r)
		return;
	int mid = tree[p].l + tree[p].r >> 1;
	if (x <= mid)
		solve(lson, x);
	else solve(rson, x);
}
int dp[maxn];
signed main()
{
	freopen("god.in", "r", stdin);
	freopen("god.out", "w", stdout);
	int n = read(), p = read();
	build(1, 1, maxn - 5);
	for (int i = 1; i <= n; i++)
	{
		int c = read(), h = read(), t = read();
		update(1, t, t + p - 1, c, h);
	}
	int q = read();
	while (q--)
	{
		vec.clear();
		aska = read(), askb = read();
		solve(1, aska);
		for (int i = 0; i <= askb; i++)
			dp[i] = 0;
		for (auto i: vec)
			for (int j = askb; j >= i.first; j--)
				dp[j] = max(dp[j], dp[j - i.first] + i.second);
		printf("%lld\n", dp[askb]);
	}
	return 0;
}
