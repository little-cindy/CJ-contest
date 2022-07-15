#include<bits/stdc++.h>
#pragma GCC optimize(2,3,"Ofast")
#define inf 1e18
#define N 4005
#define M 20005
#define ls k<<1
#define rs k<<1|1
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
struct Goods{int c,h,t;}g[N],tmp[2][N];
struct Query{int a,b,ans,dp[N];}que[M];
int n,p,q,day,money;
namespace SGT{
	vector<int>tr[M<<2];int dp[N];
	void Modify(int k,int l,int r,int x,int y,int z){
		if(l>=x&&r<=y)return void(tr[k].pb(z));
		if(x<=mid)Modify(ls,l,mid,x,y,z);
		if(mid<y)Modify(rs,mid+1,r,x,y,z);
	}
	void Divide(int k,int l,int r,int x,int y){
		if(x>y)return;
		for(int i=0;i<=money;i++)dp[i]=0;
		for(int i=x;i<=y;i++)
			for(int j=money;j>=g[i].c;j--)
				dp[j]=max(dp[j],dp[j-g[i].c]+g[i].h);
		for(auto u:tr[k])
			for(int j=que[u].b;j>=0;j--)
				for(int k=j;k>=0;k--)
					que[u].dp[j]=max(que[u].dp[j],que[u].dp[k]+dp[j-k]);
		if(l==r)return;
		int cnt[2]={0,0};
		for(int i=x;i<=y;i++)
			if(g[i].t<=mid)tmp[0][++cnt[0]]=g[i];
			else tmp[1][++cnt[1]]=g[i];
		for(int i=1;i<=cnt[0];i++)g[i+x-1]=tmp[0][i];
		for(int i=1;i<=cnt[1];i++)g[i+cnt[0]+x-1]=tmp[1][i];
		Divide(ls,l,mid,x,x+cnt[0]-1);
		Divide(rs,mid+1,r,x+cnt[0],y);
	}
}
using namespace SGT;
signed main(){
	file("god");
	n=read();p=read();
	for(int i=1;i<=n;i++)g[i].c=read(),g[i].h=read(),g[i].t=read();
	q=read();
	for(int i=1;i<=q;i++){
		que[i].a=read();que[i].b=read();
		day=max(day,que[i].a);
		money=max(money,que[i].b);
	}
	for(int i=1;i<=q;i++)Modify(1,1,day,max(1,que[i].a-p+1),que[i].a,i);
	Divide(1,1,day,1,n);
	for(int i=1;i<=q;i++)printf("%d\n",que[i].dp[que[i].b]);
    return 0;
}
