#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,y;
}edge[200005];
int query[200005];
int father[200005];
int ans[200005];
int vis[200005];
bool bj[200005];
vector<int> ed[200005];
int find(int x){
	if(father[x]==x)return x;
	return father[x]=find(father[x]);
}
void unionn(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	father[fx]=fy;
	return;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x++,y++;
		edge[i]=node{x,y};
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	int k;
	scanf("%d",&k);
//	printf("*%d\n",k);
	for(int i=1;i<=k;i++){
		scanf("%d",&query[i]);
		query[i]++;
		bj[query[i]]=true;
	}
	for(int i=1;i<=m;i++){
		int u=edge[i].x,v=edge[i].y;
		if(bj[u]||bj[v]){
			continue;
		}
		unionn(u,v);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int fx=find(i);
		if(vis[fx]!=-1){
			sum++;
			vis[fx]=-1;
		}
	}
	sum-=k;
	for(int i=k;i>=1;i--){
		ans[i]=sum;
		int x=query[i];
		bj[x]=false;
		int cnt=0;
		for(int j=0;j<ed[x].size();j++){
			int v=ed[x][j];
			if(bj[v])continue;
			if(vis[find(v)]!=i){
				vis[find(v)]=i;
				cnt++;
			}
		}
		for(int j=0;j<ed[x].size();j++){
			int v=ed[x][j];
			if(bj[v])continue;
			unionn(x,v);
		}
		sum++;
		sum-=(cnt);
	}
	ans[0]=sum;
	for(int i=0;i<=k;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7
*/
