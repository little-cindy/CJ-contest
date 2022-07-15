#include<bits/stdc++.h>
using namespace std;
int n,m,k,dt[400005],ans[400005],fa[400005];
bool f[400005];
struct edge{
	int x,y;
}e[200005];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void union_(int x,int y){
	fa[x]=find(y);
}
int count(){
	int ret=0;
	for(int i=1;i<=n;i++)
		if(!f[i]&&fa[i]==i)
			ret++;
	return ret;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y;
		e[i].x++,e[i].y++;
	}
	cin>>k;
	for(int i=k;i>=1;i--){
		cin>>dt[i];
		dt[i]++;
		f[dt[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if((!f[e[i].x])&&(!f[e[i].y]))
			union_(e[i].x,e[i].y);
		ans[0]=count();
	}
	for(int i=1;i<=k;i++){
		f[dt[i]]=0;
		for(int j=1;j<=m;j++)
			if(((!f[e[j].x])&&(e[j].y==dt[i]))||((!f[e[j].y])&&(e[j].x==dt[i])))
				union_(e[j].x,e[j].y);
		ans[i]=count();
	}
	for(int i=k;i>=0;i--)
		cout<<ans[i]<<endl;
	return 0;
}
