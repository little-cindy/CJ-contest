#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int f[500005][25];
int hd[500005],tot;
struct road{
	int to;
	int next;
}a[1000005];
int v[100005];
int dep[500005];
queue<int> q;
void find(){
	
	dep[s]=1;
//	f[s][0]=-1;
	q.push(s);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=hd[x];i;i=a[i].next){
			int y=a[i].to;
			if(dep[y]!=0) continue;
			dep[y]=dep[x]+1;
			f[y][0]=x;
			for(int j=1;j<=20;j++) f[y][j]=f[f[y][j-1]][j-1]; 
			q.push(y);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
//	cout<<x<<"_"<<y<<endl;
	if(x==y) return x;
//	cout<<f[2][0]<<"*"<<endl;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
//	cout<<x<<"*"<<y<<endl;
	return f[y][0];
}
int rd(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void add(int x,int y){
	tot++;
	a[tot].next=hd[x];
	hd[x]=tot;
	a[tot].to=y;
}
int ans;
int main(){
	freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
	n=rd();
	bool fl=0;
	for(int i=1;i<=n;i++) v[i]=rd();
	for(int i=1;i<n;i++){
		int x=rd();
		if(x!=i-1) fl=1;
		add(x,i+1);
		add(i+1,x);
	}
	find();
	if(fl==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			int v=0;
			for(int j=i;j<=n;j++){
				v=(v^(dep[j]-dep[i]+j-i));
			}
			ans+=v;
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
