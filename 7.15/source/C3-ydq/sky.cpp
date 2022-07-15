#include <bits/stdc++.h>
using namespace std;

const int N = 400010;

int n , cnt , a[N] , ys[N] , num[N] , p[N] , ans[500][500];
map<int , int> q;
pair<int , int> b[N];

inline int read()
{
    int asd = 0 , qwe = 1; char zxc;
    while(!isdigit(zxc = getchar())) if(zxc == '-') qwe = -1;
    while(isdigit(zxc)) asd = asd * 10 + zxc - '0' , zxc = getchar();
    return asd * qwe;
}

inline bool cmp(pair<int , int> x , pair<int , int> y)
{
    return x.first > y.first;
}

inline int solve(int k)
{
    priority_queue<int , vector<int> , greater<int> > q;
    for(int i = cnt - k + 1;i <= cnt;i++)
        q.push(num[i]);
    for(int i = cnt - k;i >= 1;i--)
    {
        int top = q.top(); q.pop();
        top += num[i] , q.push(top);
    }
    return q.top();
}

inline void calc(int x , int y)
{
    priority_queue<pair<int , int> > qs;
    for(int i = 1;i <= y;i++)
        qs.push(make_pair(x , i)) , p[i] = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(qs.empty()) break;
        int top = qs.top().first; 
        int id = qs.top().second , k = 0;
        qs.pop() , top -= (k = min(b[i].first , top));
        if(top > 0) qs.push(make_pair(top , id));
        for(int j = 1;j <= k;j++)
        {
            p[id]++;
            ans[p[id]][(id - p[id] + 1 + y) % y + 1] = b[i].second;
        }
    }
}

int main()
{
    freopen("sky.in" , "r" , stdin);
    freopen("sky.out" , "w" , stdout);
    n = read();
    for(int i = 1;i <= n;i++)
    {
        a[i] = read();
        if(q.find(a[i]) == q.end())
            q[a[i]] = ++cnt , ys[cnt] = a[i];
        a[i] = q[a[i]] , num[a[i]]++;
    }
    for(int i = 1;i <= cnt;i++)
        b[i] = make_pair(num[i] , ys[i]);
    sort(b + 1 , b + cnt + 1 , cmp);
    sort(num + 1 , num + cnt + 1);
    int l = 0 , r = 0;
    for(int i = cnt;i >= sqrt(cnt);i--)
    {
        int x = i , y = n / i;
        if(x * min(x , y) > l * r)
        {
            int z = solve(x);
            if(x * min(x , z) > l * r) l = x , r = min(x , z);
            if(l * r == n || (l == cnt && r == cnt)) break;
        }
    }
    if(l > r) swap(l , r);
    calc(l , r);
    printf("%d\n" , l * r);
    printf("%d %d\n" , l , r);
    for(int i = 1;i <= l;i++ , puts(""))
        for(int j = 1;j <= r;j++)
            printf("%d " , ans[i][j]);
    return 0;
}