#include<bits/stdc++.h>
using namespace std;template<typename T>void read(T&x){
	x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-1;
	do x=x*10+c-'0';while(isdigit(c=getchar()));x*=f;
}
template<typename T,typename...O>void read(T&x,O&...o){read(x),read(o...);}
#define pb push_back
const int N=4e5+5;int n,m,k,d[N],fa[N],ans[N],num,tmp[N];bool vis[N];vector<int>e[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("liu.in","r",stdin),freopen("liu.out","w",stdout);
	read(n,m);for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1,x,y;i<=m;++i)read(x,y),x++,y++,e[x].pb(y),e[y].pb(x);
	read(k);for(int i=1;i<=k;++i)read(d[i]),d[i]++,vis[d[i]]=1;
	for(int i=1;i<=n;++i){if(vis[i])continue;for(int j:e[i]){if(vis[j])continue;fa[find(i)]=find(j);}}
	for(int i=1;i<=n;++i){int j=find(i);if(vis[j])continue;tmp[j]=1;}
	for(int i=1;i<=n;++i)num+=tmp[i];ans[k+1]=num;
	for(int i=k;i>=1;--i){
		vis[d[i]]=0,num++;
		for(int j:e[d[i]]){if(vis[j])continue;int u=find(d[i]),v=find(j);if(u^v)fa[u]=v,num--;}
		ans[i]=num;
	}for(int i=1;i<=k+1;++i)printf("%d\n",ans[i]);
	return 0;
}
