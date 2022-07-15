#include<bits/stdc++.h>
using namespace std;template<typename T>void read(T&x){
	x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-1;
	do x=x*10+c-'0';while(isdigit(c=getchar()));x*=f;
}
template<typename T,typename...O>void read(T&x,O&...o){read(x),read(o...);}
#define ll long long
#define pb push_back
#define ls p<<1
#define rs ls|1
#define mid ((l+r)>>1)
#define LS ls,l,mid
#define RS rs,mid+1,r
const int N=525015;int n,v[N],f[N],d[N],c[N],sz[N],s[N],T,t[N],dfn[N];vector<int>e[N],tag[N<<2];
void dfs1(int x){d[x]=d[f[x]]+1,c[x]=v[x]+d[x],sz[x]=1;for(int v:e[x]){dfs1(v),sz[x]+=sz[v];if(!s[x]||sz[s[x]]<sz[v])s[x]=v;}}
namespace sub1{
	int dfs2(int x,int top){int ans=c[x]-d[top];for(int v:e[x])ans^=dfs2(v,top);return ans;}
	ll dfs1(int x){ll ans=dfs2(x,x);for(int v:e[x])ans+=dfs1(v);return ans;}void work(){cout<<dfs1(1)<<endl;}
}
void dfs2(int x,int top){t[x]=top,dfn[x]=++T;if(s[x])dfs2(s[x],top);for(int v:e[x])if(v^s[x])dfs2(v,v);}
void Xor(int x,int y,int z,int p=1,int l=1,int r=n){
	if(r<x||y<l)return;if(x<=l&&r<=y){tag[p].pb(z+x-l);return;}Xor(x,y,z,LS),Xor(x,y,z,RS);
}
int ask(int x,int ans=0,int p=1,int l=1,int r=n){
	if(r<x||x<l)return 0;for(int j:tag[p])ans^=j+l-x;if(l==r)return ans;return ask(x,ans,LS)^ask(x,ans,RS);
}
void chg(int p){int x=p;while(t[x]^1)Xor(dfn[t[x]],dfn[x],c[p]-d[t[x]]),x=f[t[x]];Xor(1,dfn[x],c[p]-1);}
ll dfs3(int x){ll ans=0;chg(x);for(int v:e[x])ans+=dfs3(v);return ans+ask(dfn[x]);}
int main(){
	freopen("smoke.in","r",stdin),freopen("smoke.out","w",stdout);
	read(n);for(int i=1;i<=n;++i)read(v[i]);for(int i=2;i<=n;++i)read(f[i]),e[f[i]].pb(i);
	dfs1(1);if(n<=2501){return sub1::work(),0;}dfs2(1,1),cout<<dfs3(1)<<endl;
	return 0;
}
