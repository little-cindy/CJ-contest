#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=4e3+5,SIZ=2e4;
int n,p,c[N],h[N],t[N],f[N][20],ans[SIZ+5],dat[(SIZ+5)<<2];
struct Query{int b,pos;};
vector<int>v[(SIZ+5)<<2];
vector<Query>q[SIZ+5];
void upd(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		v[p].push_back(k);
		return;
	}
	int mid=l+r>>1;
	if(L<=mid)upd(p<<1,l,mid,L,R,k);
	if(R>mid)upd(p<<1|1,mid+1,r,L,R,k);
}
void add(int p,int l,int r,int P,Query x){
	dat[p]=max(dat[p],x.b);
	if(l==r){
		q[l].push_back(x);
		return;
	}
	int mid=l+r>>1;
	if(P<=mid)add(p<<1,l,mid,P,x);
	else add(p<<1|1,mid+1,r,P,x);
}
void dfs(int p,int l,int r,int dep){
	if(!dat[p])return;
	for(int i=0;i<=dat[p];i++)f[i][dep]=f[i][dep-1];
	for(int i:v[p]){
		for(int j=dat[p];j>=c[i];j--){
			f[j][dep]=max(f[j][dep],f[j-c[i]][dep]+h[i]);
		}
	}
	if(l==r){
		for(auto i:q[l])ans[i.pos]=f[i.b][dep];
		return;
	}
	int mid=l+r>>1;
	dfs(p<<1,l,mid,dep+1);
	dfs(p<<1|1,mid+1,r,dep+1);
}
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",c+i,h+i,t+i);
		upd(1,1,SIZ,t[i],min(t[i]+p-1,SIZ),i);
	}
	int Q;scanf("%d",&Q);
	for(int i=1,a,b;i<=Q;i++){
		scanf("%d%d",&a,&b);
		add(1,1,SIZ,a,{b,i});
	}
	dfs(1,1,SIZ,1);
	for(int i=1;i<=Q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
