#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
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

int n,val[N],fa[N];
vector<int> son[N],ss[N];
int dep[N];
int ans=0;
void dfs1(int now)
{
    ss[now].push_back(now);
    dep[now]=dep[fa[now]]+1;
    for(auto v:son[now])
    {
        dfs1(v);
        for(auto vv:ss[v])
        {   
            ss[now].push_back(vv);
        }
    }
    int k=0;
    for(auto i:ss[now])
        k^=(val[i]+dep[i]-dep[now]);
    ans+=k;
}
signed main()
{
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
        val[i]=read();
    for(int i=2;i<=n;i++)
    {
        int x=read();
        fa[i]=x;
        son[x].push_back(i);
    }
    dfs1(1);
    cout<<ans;
    return 0;
}