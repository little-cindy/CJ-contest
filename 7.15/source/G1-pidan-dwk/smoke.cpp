#include<bits/stdc++.h>
//#pragma GCC optimize(2,3,"Ofast")
#define ll long long
#define inf 1e18
#define N 525015
#define mid ((l+r)>>1)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define il inline
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
il int read(){
    int w=0,h=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
    while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
    return w*h;
}
struct Edge{int next,to;}edge[N<<1];
int n,val[N],m=1050020;ll ans;
int head[N],num;
void add(int u,int v){
	edge[++num].next=head[u];
	edge[num].to=v;head[u]=num;
}
namespace Trie{
	int ch[N<<6][2],siz[N<<6],cnt[N<<6],sum[N<<6],dep[N<<6],rt[N],tot;
	void Pushup(int u){
		siz[u]=siz[ch[u][0]]+siz[ch[u][1]]+cnt[u];
		sum[u]=sum[ch[u][0]]+sum[ch[u][1]]+((siz[u]&1)<<dep[u]);
	}
	void Insert(int u,int val,int d){
		if(!val)return void(siz[u]++),void(cnt[u]++);
		int p=val&1;ch[u][p]=++tot;dep[u]=d;
		Insert(ch[u][p],val>>1,d+1);
		Pushup(u);
	}
	void Add(int&u,int tag){
		if(ch[u][0])Add(ch[u][0],0);
		if(ch[u][1])Add(ch[u][1],1);
		if(tag&&cnt[u]&&!ch[u][0]){
			ch[u][0]=++tot;
			dep[ch[u][0]]=dep[u]+1;
			siz[ch[u][0]]+=cnt[u];
			cnt[ch[u][0]]+=cnt[u];
			cnt[u]=0;
		}
		if(tag)swap(ch[u][0],ch[u][1]);
		Pushup(u);
	}
	int Merge(int x,int y){
		if(!x||!y)return x|y;
		ch[x][0]=Merge(ch[x][0],ch[y][0]);
		ch[x][1]=Merge(ch[x][1],ch[y][1]);
		Pushup(x);return x;
	}
}
using namespace Trie;
void dfs(int u,int fa){
	Insert(rt[u]=++tot,val[u],0);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		if(siz[rt[u]]<siz[rt[v]])rt[u]=Merge(rt[v],rt[u]);
		else rt[u]=Merge(rt[u],rt[v]);
	}
	ans+=sum[rt[u]];
	Add(rt[u],1);
}
signed main(){
	file("smoke");
	n=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=2;i<=n;i++)add(read(),i);
	dfs(1,0);
	printf("%lld\n",ans);
    return 0;
}
