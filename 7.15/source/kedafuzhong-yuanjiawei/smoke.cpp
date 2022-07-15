#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N=525020,M=N*2;

int n;
LL v[N];
int depth[N];
vector<int> subchild[N];

struct Edge
{
	int to;
	int next;
}e[M];

int head[N],idx;

void AddEdge(int a,int b)
{
	idx++;
	e[idx].to=b;
	e[idx].next=head[a];
	head[a]=idx;
}

void dfs(int u,int fa)
{
	depth[u]=depth[fa]+1;
	subchild[u].push_back(u);
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].to!=fa)
		{
			dfs(e[i].to,u);
			for(auto x:subchild[e[i].to])subchild[u].push_back(x);
		}
	}
}

LL calc(int u)
{
	LL ans=0;
	for(auto x:subchild[u])
	{
		ans=ans^(v[x]+depth[x]-depth[u]);
	}
	return ans;
}

int main()
{
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=2;i<=n;i++)
	{
		int fa;
		scanf("%d",&fa);
		AddEdge(i,fa);
		AddEdge(fa,i);
	}
	dfs(1,1);
	LL res=0;
	for(int i=1;i<=n;i++)
	{
		res+=calc(i);
	}
	printf("%lld\n",res);
	return 0;
}
