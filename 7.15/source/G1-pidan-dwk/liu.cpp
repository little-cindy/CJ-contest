#include<bits/stdc++.h>
#pragma GCC optimize(2,3,"Ofast")
#define int long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int read(){
    int w=0,h=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')h=-h;ch=getchar();}
    while(ch>='0'&&ch<='9'){w=w*10+ch-'0';ch=getchar();}
    return w*h;
}
struct node{
	int next,from,to;
}edge[800010];
int n,m,k,num,father[800010],head[800010],broken[800010],ans[800010];
bool vis[800010];
int find_father(int u){
	if(father[u]==u)return u;
	return father[u]=find_father(father[u]);
}
void add(int x,int y){
	edge[++num].next=head[x];
	edge[num].from=x;edge[num].to=y;
	head[x]=num;
}
signed main(){
	file("liu");
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)father[i]=i;
	for(int i=0;i<m;i++){
		int x,y;scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}scanf("%lld",&k);
	for(int i=1;i<=k;i++)scanf("%lld",&broken[i]),vis[broken[i]]=1;
	int tot=n-k;
	for(int i=0;i<m*2;i++){
		if(!vis[edge[i].from]&&!vis[edge[i].to]){
			int fx=find_father(edge[i].from),fy=find_father(edge[i].to);
			if(fx!=fy){
				tot--;
				father[fx]=fy;
			}
		}
	}
	ans[k+1]=tot;
	for(int i=k;i>=1;i--){
		int u=broken[i];tot++;vis[u]=0;
		for(int j=head[u];j;j=edge[j].next){
			if(!vis[edge[j].to]){
				int fx=find_father(u),fy=find_father(edge[j].to);
				if(fx!=fy){
					tot--;
					father[fx]=fy;
				}
			}
		}
		ans[i]=tot;
	}
	for(int i=1;i<=k+1;i++)printf("%lld\n",ans[i]);
    return 0;
}
