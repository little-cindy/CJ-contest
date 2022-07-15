#include<bits/stdc++.h>

using namespace std;

const int N=4e5+5;

struct E{
	int Next,v,u;
}edge[N<<1];

int n,m;
int fa[N];
int cnt,head[N];
int shan[N],query[N];
int lkr[N];
int dian;

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void unionn(int x,int y){
	int fax=find(x),fay=find(y);
	if(fax!=fay) fa[fax]=fay,dian--;
	return;
}
inline void addedge(int from,int to){
	edge[++cnt]={head[from],to,from};
	head[from]=cnt;
	return;
}

int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v,u++,v++;
		addedge(u,v),addedge(v,u);
	}
	int k;cin>>k,dian=n-k;
	for(int i=1;i<=k;i++){
		cin>>query[i],query[i]++;
		shan[query[i]]=true;
	}
	for(int i=1;i<=2*m;i++){
		int u=edge[i].u,v=edge[i].v;
		if(shan[u]==false&&shan[v]==false) unionn(u,v);
	}
	lkr[k+1]=dian; 
	for(int i=k;i>=1;i--){
		int u=query[i]; shan[u]=false;
		dian++;
		for(int j=head[u];j!=0;j=edge[j].Next){
			int v=edge[j].v;
			if(shan[v]==false) unionn(u,v);
		}
		lkr[i]=dian;
	}
	for(int i=1;i<=k+1;i++) cout<<lkr[i]<<'\n';
	return 0;
}
