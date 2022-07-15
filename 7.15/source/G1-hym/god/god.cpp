#include<bits/stdc++.h>
using namespace std;template<typename T>void read(T&x){
	x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-1;
	do x=x*10+c-'0';while(isdigit(c=getchar()));x*=f;
}
template<typename T,typename...O>void read(T&x,O&...o){read(x),read(o...);}
#define pii pair<int,int>
#define pb push_back
#define ls p<<1
#define rs ls|1
#define mid ((l+r)>>1)
#define LS ls,l,mid
#define RS rs,mid+1,r
const int N=4e3+5,A=2e4+5;
int n,p,q,c[N],h[N],t[N],mxa,mxb,f[N][N],num,ans[A];
vector<pii>qry[A];vector<int>sp[A<<2];
void add(int x,int y,int z,int p=1,int l=1,int r=mxa){
	if(x>y||r<x||y<l)return;
	if(x<=l&&r<=y){sp[p].pb(z);return;}
	add(x,y,z,LS),add(x,y,z,RS);
}
void dfs(int p=1,int l=1,int r=mxa){
	int tmp=num;
	for(int i:sp[p]){
		++num;for(int j=0;j<=mxb;++j)f[num][j]=f[num-1][j];
		for(int j=mxb;j>=c[i];--j)f[num][j]=max(f[num][j],f[num-1][j-c[i]]+h[i]);
	}
	if(l==r)for(pii i:qry[l])ans[i.first]=f[num][i.second];
	else dfs(LS),dfs(RS);num=tmp;
}
int main(){
	freopen("god.in","r",stdin),freopen("god.out","w",stdout);
	read(n,p);for(int i=1;i<=n;++i)read(c[i],h[i],t[i]);
	read(q);for(int i=1,a,b;i<=q;++i)read(a,b),qry[a].pb({i,b}),mxa=max(mxa,a),mxb=max(mxb,b);
	for(int i=1;i<=n;++i)add(t[i],min(t[i]+p-1,mxa),i);
	dfs();for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}
