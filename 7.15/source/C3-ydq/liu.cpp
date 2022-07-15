#include <bits/stdc++.h>
using namespace std;

const int N = 400010;

int n , m , k , cnt , tot , sum , fa[N] , siz[N] , ans[N] , ton[N];

pair<int , int> a[N];

inline int read()
{
    int asd = 0 , qwe = 1; char zxc;
    while(!isdigit(zxc = getchar())) if(zxc == '-') qwe = -1;
    while(isdigit(zxc)) asd = asd * 10 + zxc - '0' , zxc = getchar();
    return asd * qwe;
}

inline int gf(int x)
{
    return (fa[x] == x ? x : fa[x] = gf(fa[x]));
}

inline void merge(int x , int y)
{
    x = gf(x) , y = gf(y);
    if(x == y) return;
    if(siz[x] < siz[y]) swap(x , y);
    fa[y] = x , sum-- , siz[x] += siz[y];
}

int main()
{
    freopen("liu.in" , "r" , stdin);
    freopen("liu.out" , "w" , stdout);
    n = read() , m = read();
    for(int i = 1;i <= n;i++) fa[i] = i , siz[i] = 1;
    for(int i = 1;i <= m;i++)
        a[i].first = read() + 1 , a[i].second = read() + 1;
    k = read();
    for(int i = 1;i <= k;i++)
    {
        int x = read() + 1;
        ton[x] = ++cnt;
    }
    for(int i = 1;i <= n;i++)
        if(!ton[i]) ton[i] = ++cnt;
    for(int i = 1;i <= m;i++)
    {
        a[i].first = ton[a[i].first];
        a[i].second = ton[a[i].second];
        if(a[i].first > a[i].second)
            swap(a[i].first , a[i].second);
    }
    sort(a + 1 , a + m + 1) , cnt = n;
    for(int i = m;i >= 1;i--)
    {
        while(a[i].first <= cnt) ans[cnt--] = sum++;
        merge(a[i].first , a[i].second);
    }
    while(cnt >= 0) ans[cnt--] = sum++;
    for(int i = 0;i <= k;i++)
        printf("%d\n" , ans[i]);
    return 0;
}