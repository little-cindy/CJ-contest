#include<bits/stdc++.h>
#define maxn 400005
#define maxm 200005
using namespace std;
int n, m, k, h[maxn]; 
int ans, f[maxn], t[maxn], fa[maxn];
bool flag[maxn];
int head[maxn], cnt;
struct Edge
{
	int to, nxt;
}edges[maxm];
void add_edge(int x, int y)
{
	cnt++;
	edges[cnt].to=y;
	edges[cnt].nxt=head[x];
	head[x]=cnt;
	return;
}
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return find(f[x]);
}
void unionn(int x, int y)
{
	int xx=find(x), yy=find(y);
	f[xx]=yy;
	fa[x]++;
	return;
}
int main()
{
  	freopen("liu.in","r",stdin);
  	freopen("liu.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		f[i]=i;
		flag[i]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
		unionn(x,y);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>h[i];
	}
	for(int i=0;i<n;i++)
	{
		t[find(i)]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]>0)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=k;i++)
	{
		flag[h[i]]=false;
		if(t[h[i]]==1)
		{
			ans--;
		}
		for(int j=head[h[i]];j;j=edges[j].nxt)
		{
			int v=edges[j].to;
			if(f[v]==h[i]&&fa[v]==1)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

