#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();int s=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
int n,m,k,a[400010],father[400010],vis[400010],ans[400010],cnt,h[400010];
struct node{
	int u,v,nxt;
}e[400010];
int find(int x){
	if(father[x]==x)
		return x;
	return father[x]=find(father[x]);
}
void add(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		father[i]=i;
	for(int i=1;i<=m;i++){
		int u=read()+1,v=read()+1;
		if(u==v)
			continue;
		add(u,v);
		add(v,u);
	}
	k=read();
	for(int i=1;i<=k;i++)
		a[i]=read()+1,vis[a[i]]=1;
	ans[k+1]=n-k;
	for(int i=1;i<=2*m;i++){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(!vis[e[i].u]&&!vis[e[i].v]&&f1!=f2)
				father[f1]=f2,ans[k+1]--;
	}
	for(int i=k;i>=1;i--){
		vis[a[i]]=0;
		ans[i]=ans[i+1]+1;
		for(int j=h[a[i]];j;j=e[j].nxt){
			int f1=find(a[i]),f2=find(e[j].v);
			if(!vis[e[j].v]&&f1!=f2)
				father[f1]=f2,ans[i]--;
		}
	}
	for(int i=1;i<=k+1;i++)
		printf("%d\n",ans[i]);
	return 0;
}
