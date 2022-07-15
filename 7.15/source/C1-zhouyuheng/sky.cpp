#include <bits/stdc++.h>

using namespace std; 

const int Maxn = 4e5 + 10; 

int n; 
int a[Maxn]; 
map<int, int> mp; 

int calc(int x) {
	int res = 0; 
	for (auto it : mp) {
		if (it.second <= x) res += it.second; 
		else res += x; 
	}
	return res; 
} 

vector<int> v[Maxn]; // 每一个列条 

int main() {
	freopen("sky.in", "r", stdin); 
	freopen("sky.out", "w", stdout); 
	int i, j; 
	scanf("%d", &n); 
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i); 
		++mp[a[i]]; 
	}
	int ans1 = 0, ans2 = 0; 
	for (i = 1; i <= n / 2; ++i) {
		// i 为行，且 行<=列 
//		if (calc(i) > n) printf("lbp love hxy %d %d\n", i, calc(i)); 
		j = calc(i) / i; 
		if (j < i) continue; 
		if (ans1 * ans2 < i * j) ans1 = i, ans2 = j; 
	}
	printf("%d\n", ans1 * ans2); 
	printf("%d %d\n", ans1, ans2); 
	for (auto it : mp) {
		if (it.second > ans1) it.second = ans1; 
	}
	int tmp = 0, tot = 1; 
	for (auto it : mp) {
//		printf("%d %d\n", it.first, tmp);  
		if (tmp + it.second < ans1) {
			tmp += it.second; 
			for (i = 1; i <= it.second; ++i) v[tot].emplace_back(it.first); 
		}
		else {
//			int xx = tmp; 
			for (i = 1; i <= ans1 - tmp; ++i) v[tot].emplace_back(it.first); 
			++tot; 
			tmp = it.second - (ans1 - tmp); 
			for (i = 1; i <= tmp; ++i) v[tot].emplace_back(it.first); 
		}
	}
//	for (i = 1; i <= ans2; ++i) {
//		printf("***%d\n", v[i].size()); 
//		for (j = 0; j < ans1; ++j) {
//			printf("%d ", v[i][j]); 
//		}
//		puts(""); 
//	}
//	printf("%d\n", tot); 
	for (i = 1; i <= ans1; ++i) {
		int t;  
		for (j = 0; j < ans2; ++j) {
			t = i + j; if (t > ans2) t -= ans2; 
			printf("%d ", v[t][i - 1]); 
		}
		puts(""); 
	}
	return 0; 
}
