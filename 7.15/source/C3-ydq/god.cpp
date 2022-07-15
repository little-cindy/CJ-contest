#include <bits/stdc++.h>
using namespace std;

const int N = 4010;
const int M = 20010;

int n , m , k , fir , f[N] , ans[M];
vector<pair<int , int> > a[M];

struct Tree
{
    int l , r;
    vector<pair<int , int> > q;
}t[M * 4];

inline int read()
{
    int asd = 0 , qwe = 1; char zxc;
    while(!isdigit(zxc = getchar())) if(zxc == '-') qwe = -1;
    while(isdigit(zxc)) asd = asd * 10 + zxc - '0' , zxc = getchar();
    return asd * qwe;
}

inline void build(int p , int l , int r)
{
    t[p].l = l , t[p].r = r;
    if(l == r) return;
    build(p * 2 , l , (l + r) / 2);
    build(p * 2 + 1 , (l + r) / 2 + 1 , r);
}

inline void change(int p , int l , int r , int c , int h)
{
    if(l <= t[p].l && t[p].r <= r)
    {
        t[p].q.push_back(make_pair(c , h));
        return;
    }
    int mid = (t[p].l + t[p].r) / 2;
    if(l <= mid) change(p * 2 , l , r , c , h);
    if(r > mid)  change(p * 2 + 1 , l , r , c , h);
}

inline void dfs(int p)
{
    int b[N];
    for(int i = 0;i <= 4000;i++) b[i] = f[i] , fir++;
    for(auto i : t[p].q)
    {
        int c = i.first , h = i.second;
        for(int i = 4000;i >= c;i--)
            f[i] = max(f[i] , f[i - c] + h);
    }
    if(t[p].l == t[p].r)
        for(auto i : a[t[p].l])
            ans[i.second] = f[i.first];
    else dfs(p * 2) , dfs(p * 2 + 1);
    for(int i = 0;i <= 4000;i++) f[i] = b[i];
}

int main()
{
    freopen("god.in" , "r" , stdin);
    freopen("god.out" , "w" , stdout);
    n = read() , m = read() , build(1 , 1 , 20000);
    for(int i = 1;i <= n;i++)
    {
        int c = read() , h = read() , ts = read();
        change(1 , ts , ts + m - 1 , c , h);
    }
    k = read();
    for(int i = 1;i <= k;i++)
    {
        int x = read() , y = read();
        a[x].push_back(make_pair(y , i));
    }
    dfs(1);
    for(int i = 1;i <= k;i++)
        printf("%d\n" , ans[i]);
    return 0;
}