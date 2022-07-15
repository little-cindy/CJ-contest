#include<bits/stdc++.h>
using namespace std;
int n,m,s,head[525015],tot,depth[525015],cnt,zs[525015],dfn[525015],_dfn[525015],v[525015];
long long ans;
struct node{
	int t,nex;
}e[1050025];
void add(int x,int y){
	e[++tot].t=y,e[tot].nex=head[x],head[x]=tot;
}
void dfs(int now,int fa){
	dfn[now]=++cnt,_dfn[cnt]=now,depth[now]=depth[fa]+1;
	for(int i=head[now];i;i=e[i].nex){
		if(e[i].t!=fa)
			dfs(e[i].t,now);
		zs[now]=cnt;
	}
}
int main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=2,x;i<=n;i++){
		cin>>x;
		add(i,x);
		add(x,i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=dfn[i];j<=zs[i];j++)
			sum^=(v[_dfn[j]]+depth[_dfn[j]]-depth[i]);
		ans+=sum;
	}
	cout<<ans;
	return 0;
}
