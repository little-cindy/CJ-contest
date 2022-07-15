#include<bits/stdc++.h>
using namespace std;
int n,m,a[400003],A,B,k,K,b[400003],C,c[400003],D,d[800003];
vector<int>v[400003],V[400003],w[400003];
void dfs(int e,int f){
	c[e]=f;++d[f];
	for(int i=0;i<a[e];++i)
	if(c[v[e][i]]==0)dfs(v[e][i],f);
}
void Dfs(int g,int h){
	--d[c[K]],++d[h];
	c[g]=h;
	for(int i=0;i<a[g];++i)
	if(w[g][i]!=-1&&c[w[g][i]]==c[K])Dfs(w[g][i],h);
}
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0')ch=getchar();
	while(ch>='0')x=x*10+ch-48,ch=getchar();
	return x;
}
inline void write(int x){
	int tmp=x,cnt=0;char F[25];
	while(tmp)F[cnt++]=tmp%10+'0',tmp/=10;
	while(cnt)putchar(F[--cnt]);
	if(x==0)putchar('0');
	putchar('\n');
	return;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<m;++i)
	A=read(),B=read(),v[A].push_back(B),w[A].push_back(B),V[A].push_back(a[B]),++a[B],v[B].push_back(A),w[B].push_back(A),V[B].push_back(a[A]),++a[A];
	for(int i=0;i<n;++i)
	if(c[i]==0)dfs(i,++C);
	write(C);
	k=read();
	for(int i=1;i<=k;++i){
		K=read();
		for(int j=0;j<a[K];++j)
		w[K][j]=w[v[K][j]][V[K][j]]=-1;
		for(int j=0;j<n;++j)
		if(c[j]==c[K]&&j!=K)Dfs(j,++C);
		c[K]=-1,d[c[K]]=0,++D;
		write(C-D);
	}
	return 0;
}
