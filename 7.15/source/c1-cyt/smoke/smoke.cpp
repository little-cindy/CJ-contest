#include <bits/stdc++.h>
using namespace std;

vector <long long> son[152511 + 1000];
long long n, ans;


struct jd {
	long long v, fa;
}e[152511 + 1000];

struct tree {
	long long c, w;
}t[152511 * 4];

inline void build (long long p, long long c) {
	t[p]. w = e[p]. v;
	t[p]. c = c;
	if (son[p]. size () == 0)
		return ;
	
	for (int i = 0; i < son[p]. size (); ++ i)
		build (son[p][i], c + 1);
}

inline long long search (long long p, long long c) {
	long long cc = t[p]. c - c;
	if (son[p]. size () == 0)
		return t[p]. w + cc;
	
	long long sum = (t[p]. w + cc);
	for (int i = 0; i < son[p]. size (); ++ i)
	    sum ^= search (son[p][i], c);
	return sum;
}

int main () {
	freopen ("smoke.in", "r", stdin);
	freopen ("smoke.out", "w", stdout);
	
	scanf ("%d", &n);
	
	for (int i = 1; i <= n; ++ i)
		scanf ("%d", &e[i]. v);
	
	bool flag = 0;
	for (int i = 2; i <= n; ++ i) {
	    scanf ("%d", &e[i]. fa);
	    son[e[i]. fa]. push_back (i);
	}
	
	build (1, 1);
	
	for (int i = 1; i <= n; ++ i)
		ans += search (i, t[i]. c);
	cout << ans;
	return 0;
}
