#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char ch=getchar();int s=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
int n,a[600010],ans,h[600010],cnt;
struct node{
	int v,nxt;
}e[600010];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
int dfs(int now,int sum){
	int sss=a[now]+sum;
	for(int i=h[now];i;i=e[i].nxt)
		sss^=dfs(e[i].v,sum+1);
	return sss;
}
signed main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(); 
	for(int i=2;i<=n;i++)
		add(read(),i);
	for(int i=1;i<=n;i++)
		ans+=dfs(i,0);
	printf("%lld",ans);
	return 0;
}
