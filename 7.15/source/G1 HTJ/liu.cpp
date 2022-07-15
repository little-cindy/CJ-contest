#include<bits/stdc++.h>
using namespace std;
int n,m,k,num;
int x,y;
int cnt;
int fa[200005];
int ans[200005];
int a[200005],bro[200005];
int getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
int h[200005];
struct hl{
	int v,nxt;
}e[400005];
struct llt{
	int u,v;
}t[400005];
void add(int u,int v)
{
	e[++cnt].v=v;e[cnt].nxt=h[u];h[u]=cnt;
	e[++cnt].v=u;e[cnt].nxt=h[v];h[v]=cnt;
}
int main()
{
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&x,&y);
		t[i].u=x;t[i].v=y;
		add(x,y);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		bro[a[i]]=1;
	}
	num=n-k;
	for(int i=1;i<=m;i++)
	{
		int fu=getfa(t[i].u),fv=getfa(t[i].v);
		if(bro[t[i].u]==0&&bro[t[i].v]==0&&fu!=fv)
		{
			num--;
			fa[fu]=fv;
		}
	}
	ans[k+1]=num;
	for(int i=k;i>0;i--)
	{
		num++;
		bro[a[i]]=0;
		for(int j=h[a[i]];j;j=e[j].nxt)
		{
			int fu=getfa(a[i]),fv=getfa(e[j].v);
			if(bro[e[j].v]==0&&fu!=fv)
			{
				num--;
				fa[fu]=fv;
			}
		}
		ans[i]=num;
	}
	for(int i=1;i<=k+1;i++) printf("%d\n",ans[i]);
}
