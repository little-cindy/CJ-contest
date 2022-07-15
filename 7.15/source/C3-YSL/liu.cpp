#include<bits/stdc++.h>
#define MAXN 200002
#define mod 100000007ll
#define ls(x) x<<1
#define rs(x) x<<1|1
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
int n,m,k;
int q[MAXN];
bool flag[MAXN],tag[MAXN];
vector<int>V[MAXN];
inline void dfs(int now)
{
    if(flag[now])return;
    flag[now]=true;
    for(int i:V[now])
        dfs(i);
}
int main()
{
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
	n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read();
        if(x==y)continue;
        V[x].push_back(y);V[y].push_back(x);
    }
    k=read();
    int res=0;
    for(int i=0;i<n;i++)
        if(!flag[i]&&!tag[i])
            dfs(i),res++;
    printf("%d\n",res);
    for(int i=1;i<=k;i++)
    {
        q[i]=read();
        for(int j:V[q[i]])
            V[j].erase(find(V[j].begin(),V[j].end(),q[i]));
        V[q[i]].clear();
        tag[q[i]]=true;
        memset(flag,0,sizeof(flag));
        int res=0;
        for(int i=0;i<n;i++)
            if(!flag[i]&&!tag[i])
                dfs(i),res++;
        printf("%d\n",res);
    }
    return 0;
}
/*
O(n^3)
*/