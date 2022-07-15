#include<bits/stdc++.h>
#define MAXN 2512
#define mod 100000007ll
using namespace std;
namespace FastIO
{
	char buf[1<<23],*p1,*p2;
	#define reg register
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2))?EOF:*p1++
	inline int read()
    {
        reg int f=1,w=0;reg char ch=gc();
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
        while(ch>='0'&&ch<='9')w=w*10+ch-'0',ch=gc();
        return f*w;
    }
}
using FastIO::read;
int n;
int ans,res;
int v[MAXN],fa[MAXN];
vector<int>V[MAXN];
inline void dfs(int now,int deep)
{
    ans^=v[now]+deep;
    for(int i:V[now])
    {
        if(i==fa[now])continue;
        dfs(i,deep+1);
    }
    return;
}
int main()
{
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
	n=read();
    for(int i=1;i<=n;i++)
        v[i]=read();
    for(int i=2;i<=n;i++)
    {
        fa[i]=read();
        V[fa[i]].push_back(i);
        V[i].push_back(fa[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ans=1;
        dfs(i,0);
        res+=ans;
    }
    printf("%d\n",res);
    return 0;
}