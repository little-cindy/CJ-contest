#include <bits/stdc++.h>
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
const int maxn = 4e5 + 5;
int a[maxn];
pair <int, int> p[maxn];
vector <int> ans[maxn];
int hang, lie, n;
//bool check(int mid)
//{
//	int tmp = mid;
//	int now1 = 0, now2 = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (tmp - p[i].first <= 0)
//		{
//			now1 = i, now2 = tmp;
//			tmp = 0;
//			break;
//		}
//		tmp -= p[i].first;
//	}
//	bool flag = 0;
//	for (int i = 1; i * i <= mid; i++)
//		if (mid % i == 0)
//		{
//			hang = i;
//			lie = mid / i;
//			for (int j = 1; j <= hang; j++)
//				vec[j].clear(), vec[j].resize(lie);
//			bool tmpflag = 0;
//			for (int j = 1; j <= now1 - 1; j++)
//				if (p[i].first > lie || p[i].first > hang)
//				{
//					tmpflag = 1;
//					break;
//				}
//			if (now2 > lie || now2 > hang)
//				tmpflag = 1;
//			if (tmpflag)
//				continue;
//			for (int j = )
//		}
//}
signed main()
{
	freopen("sky.in", "r", stdin);
	freopen("sky.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) 
		a[i] = read();
//	sort(a + 1, a + 1 + n);
//	bool flag = 0;
//	for (int i = 1; i <= n; i++)
//		if (a[i] == a[i - 1])
//		{
//			flag = 1;
//			break;
//		}
//	if (!flag)
//	{
		printf("%d\n", n);
		printf("%d %d\n", 1, n);
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
//	}
//	else
//	{
//		int nowcnt = 0, cnt = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			nowcnt++;
//			if (a[i] != a[i + 1])
//				p[++cnt].first = nowcnt, p[++cnt].second = a[i], nowcnt = 0;
//		}
//		sort(p + 1, p + 1 + n);
//		int l = 0, r = n + 1;
//		while (l + 1 < r)
//		{
//			int mid = l + r >> 1;
//			if (check(mid))
//				l = mid;
//			else r = mid;
//		}
//		printf("%d\n%d %d\n", l, hang, lie);
//		for (int i = 1; i <= hang; i++, puts(""))
//			for (int j: ans[i])
//				printf("%d ", j);
//	}
	return 0;
}
