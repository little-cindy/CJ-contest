#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+5;

inline int read()
{
    register int x=0,f=1;
    register char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int n,m;
int fa[MAXN];
int x[MAXN],y[MAXN];
int ans;

inline int find(int x)
{
    if(x==fa[x])
        return fa[x];
    return fa[x]=find(fa[x]);
}

inline void merge(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
    {
        fa[a]=b;
    }
    return;
}

inline void init()
{
    for(register int i=0;i<=n-1;i++)
        fa[i]=i;
    ans=0;
    return;
}

inline void solve()
{
    for(register int i=0;i<=n-1;i++)
    {
        if(fa[i]==i)
            ans++;
    }
    return;
}

int k;
bool vis[MAXN];

int main()
{
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    memset(vis,false,sizeof(vis));
    n=read(),m=read();
    init();
    for(register int i=1;i<=m;i++)
    {
        x[i]=read(),y[i]=read();
        merge(x[i],y[i]);
    }
    solve();
    printf("%d\n",ans);
    k=read();
    for(register int i=1;i<=k;i++)
    {
        int fu=read();
        init();
        vis[fu]=true;
        for(register int i=1;i<=m;i++)
        {
            if(vis[x[i]]==true || vis[y[i]]==true)
                continue;
            merge(x[i],y[i]);
        }
        solve();
        printf("%d\n",ans-i);
    }
    return 0;
}