#include<bits/stdc++.h>
using namespace std;
const int MAXN=6e5+5;
struct node
{
    int to,nxt;
}e[MAXN];
int head[MAXN],cnt;
int n;
inline void add(int x,int y)
{
    e[++cnt].to=y;
    e[cnt].nxt=head[x];
    head[x]=cnt;
}
int fa[MAXN];
int val[MAXN],dep[MAXN];
inline void dfs(int x)
{
    dep[x]=dep[fa[x]]+1;
    for(register int i=head[x];i;i=e[i].nxt)
    {
        int y=e[i].to;
        dfs(y);
    }
}
int nans;
inline void down(int dp,int x)
{
    nans^=(val[x]+dep[x]-dp);
    for(register int i=head[x];i;i=e[i].nxt)
    {
        int y=e[i].to;
        down(dp,y);
    }
}
int main()
{
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    for(register int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        add(fa[i],i);
    }
    dfs(1);
    int ans=0;
    for(register int i=1;i<=n;i++)
    {
        nans=0;
        down(dep[i],i);
        ans+=nans;
    }
    printf("%d",ans);
    return 0;
}