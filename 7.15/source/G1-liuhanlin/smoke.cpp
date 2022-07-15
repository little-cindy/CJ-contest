#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10,M=N*25,B=21;
int n,v[N],t[M][2],w[M],ov[M],rt[N],s,h[N],to[N*2],fr[N*2],ts;
long long ans;
int build(){
    s++;t[s][0]=t[s][1]=w[s]=ov[s]=0;
    return s;
}
void add(int x,int y){
    ts++;fr[ts]=h[x],to[ts]=y;h[x]=ts;
}
void xg(int x){
    w[x]=ov[x]=0;
    if(t[x][0]) w[x]+=w[t[x][0]],ov[x]^=(ov[t[x][0]]<<1);
    if(t[x][1]) w[x]+=w[t[x][1]],ov[x]^=((ov[t[x][1]]<<1)|w[t[x][1]]);
    w[x]&=1;
}
void addt(int &x,int d,int y){
    if(!x) x=build();
    if(d>B){
	w[x]++;
	return;
    }
    addt(t[x][y&1],d+1,y>>1);
    xg(x);
}
void addall(int x){
    swap(t[x][0],t[x][1]);
    if(t[x][0]) addall(t[x][0]);
    xg(x);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    w[x]=(w[x]+w[y])&1,ov[x]^=ov[y];
    t[x][0]=merge(t[x][0],t[y][0]);
    t[x][1]=merge(t[x][1],t[y][1]);
    return x;
}
void dfs(int x,int f){
    for(int i=h[x];i;i=fr[i]){
	if(f==to[i]) continue;
	dfs(to[i],x);
	rt[x]=merge(rt[x],rt[to[i]]);
    }
    addall(rt[x]);
    addt(rt[x],0,v[x]);
    ans+=ov[rt[x]];
}
int main(){
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=2,x;i<=n;i++){
	scanf("%d",&x);
	add(x,i);add(i,x);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}
