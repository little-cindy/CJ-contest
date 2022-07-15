#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> nbr[200005];
int vis[200005],now;
int kill[200005],ans[200005],fa[200005];
int find(int x){return fa[x]=(fa[x]==x)?x:find(fa[x]);};
void unionn(int x,int y)
{
	int xx=find(x),yy=find(y);
	if(xx==yy)
		return ;
	now--;
	fa[xx]=yy;
}
int main()
{
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout); 
//	cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		nbr[x].push_back(y);
		nbr[y].push_back(x);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>kill[i];vis[kill[i]]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			now++;
			for(int j=0;j<nbr[i].size();j++)
				if(vis[nbr[i][j]]==0)
					unionn(i,nbr[i][j]);
		}
	for(int i=k;i>0;i--)
	{
		int x=kill[i];
		vis[x]=0;
		now++;
		for(int j=0;j<nbr[x].size();j++)
			if(vis[nbr[x][j]]==0)
				unionn(x,nbr[x][j]);
		ans[i]=now;
	}
	for(int i=1;i<=k;i++){
		printf("%d",ans[i]);
		puts("");
	}
    return 0;
}

