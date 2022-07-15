#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
const int N = 2e4 + 5; 
const int lim = 2e4; 
#define pii pair<int, int>
#define mp(i, j) make_pair(i, j)
using namespace std;

int n, p, r[N], l[N], cnt, m, ans; 
vector<pii > vec[N];
struct node { int f[4005]; } a[10005]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

void calc(int k, int c, int v)
{
	for(int i = 4000; i >= c; i--)
		a[k].f[i] = max(a[k].f[i], a[k].f[i - c] + v); 
}

int main()
{
	freopen("god.in", "r", stdin);
	freopen("god.out", "w", stdout);
	n = read <int> (), p = read <int> ();
	for(int c, h, t, i = 1; i <= n; i++)
	{
		c = read <int> (), h = read <int> (), t = read <int> (); 
		vec[t].push_back(mp(c, h)); 
	}
	for(int sz, i = 1; i <= lim; i += p)
	{
		for(int j = 0; j < p && i + j <= lim; j++)
		{
			if(j) r[i + j] = r[i + j - 1]; 
			if(vec[i + j].size())
			{
				sz = vec[i + j].size(), a[++cnt] = a[r[i + j]], r[i + j] = cnt; 
				for(int k = 0; k < sz; k++)
					calc(cnt, vec[i + j][k].first, vec[i + j][k].second); 
			}
		}
		for(int j = 1; j < p && i - j >= 1; j++)
		{
			if(j > 1) l[i - j] = l[i - j + 1]; 
			if(vec[i - j].size())
			{
				sz = vec[i - j].size(), a[++cnt] = a[l[i - j]], l[i - j] = cnt; 
				for(int k = 0; k < sz; k++)
					calc(cnt, vec[i - j][k].first, vec[i - j][k].second); 
			}
		}
	}
	m = read <int> (); 
	int pos, k; 
	while(m--)
	{
		pos = read <int> (), k = read <int> (), ans = 0;
		for(int i = 0; i <= k; i++)
			ans = max(ans, a[l[max(pos - p + 1, 0)]].f[i] + a[r[pos]].f[k - i]); 
		printf("%d\n", ans); 
	}
	return 0; 
}
