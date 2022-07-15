#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1000010;

struct Edge
{
	int to;
	int next;
}e[N];

int head[N],idx;

void AddEdge(int a,int b)
{
	idx++;
	e[idx].to=b;
	e[idx].next=head[a];
	head[a]=idx;
}
int n,m,k;
int a[N];
int s[N];
int q[N];
int hh=0,tt=-1;

bool no[N];

void bfs(int u,int cnt)
{
	q[++tt]=u;
	while(hh<=tt)
	{
		u=q[hh++];
		s[u]=cnt;
		for(int i=head[u];i;i=e[i].next)
		{
			if(!s[e[i].to]&&!no[e[i].to])
			{
				q[++tt]=e[i].to;
			}
		}
	}
}

int main()
{
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a++;
		b++;
		AddEdge(a,b);
		AddEdge(b,a);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		a[i]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!s[i])
		{
			cnt++;
			bfs(i,cnt);
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=k;i++)
	{
		memset(s,0,sizeof s);
		cnt=0;
		no[a[i]]=true;
		for(int j=1;j<=n;j++)
		{
			if(!s[j]&&!no[j])
			{
				cnt++;
				bfs(j,cnt);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}


