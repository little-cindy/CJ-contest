#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6e5;

int n , m , cnt , sum , v[N] , fa[N] , ans[N] , head[N];

struct edge
{
    int to , nxt;
}e[N * 2];

inline int read()
{
    int asd = 0 , qwe = 1; char zxc;
    while(!isdigit(zxc = getchar())) if(zxc == '-') qwe = -1;
    while(isdigit(zxc)) asd = asd * 10 + zxc - '0' , zxc = getchar();
    return asd * qwe;
}

inline void add(int x , int y)
{
    e[++cnt] = {y , head[x]} , head[x] = cnt;
    e[++cnt] = {x , head[y]} , head[y] = cnt;
}

inline void dfs(int now , int sum , int k)
{
    ans[k] ^= (sum + v[now]);
    for(int i = head[now];i;i = e[i].nxt)
    {
        if(e[i].to == fa[now]) continue;
        dfs(e[i].to , sum + 1 , k);
    }
}

signed main()
{
    freopen("smoke.in" , "r" , stdin);
    freopen("smoke.out" , "w" , stdout);
    n = read();
    for(int i = 1;i <= n;i++)
        v[i] = read();
    for(int i = 2;i <= n;i++)
        fa[i] = read() , add(i , fa[i]);
    for(int i = 1;i <= n;i++)
        dfs(i , 0 , i);
    for(int i = 1;i <= n;i++)
        sum += ans[i];
    cout << sum << endl;
    return 0;
}