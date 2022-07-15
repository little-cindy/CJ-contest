#include<bits/stdc++.h>
using namespace std;

int read()
{
    int r=0,f=1;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-')f=0;
        c=getchar();
    }
    while(isdigit(c))
    {
        r=(r<<1)+(r<<3)+c-48;
        c=getchar();
    }
    return f?r:-r;
}

const int N=1e6+5;
int n,m,k,broke[N],cnt;
vector<int> to[N];
struct node
{
    int u,v;
}bian[N<<1];
bool vis[N];
int fa[N];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int ans[N];
int main()
{
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    n=read(); m=read();
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int u,v,i=1;i<=m;i++)
    {
        u=read()+1; v=read()+1;
        to[u].push_back(v);
        to[v].push_back(u);
        bian[i].u=u; bian[i].v=v;
    }
    k=read();
    for(int i=1;i<=k;i++)
    {
        broke[i]=read()+1;
        vis[broke[i]]=1;
    }
    int siz=n-k;
    for(int i=1;i<=m;i++)
    {
        if(!vis[bian[i].u]&&!vis[bian[i].v])
        {
            int xx=find(bian[i].u),yy=find(bian[i].v);
            if(xx!=yy) fa[xx]=yy,siz--;
        }
    }
    ans[k]=siz;
    for(int i=k;i>=1;i--)
    {
        vis[broke[i]]=0;
        siz++;
        for(auto v:to[broke[i]])
        {
            if(!vis[v])
            {
                int xx=find(broke[i]),yy=find(v);
                if(xx!=yy) fa[xx]=yy,siz--;
            }
        }
        ans[i-1]=siz;
    }
    for(int i=0;i<=k;i++)
        printf("%d\n",ans[i]);
    return 0;
}