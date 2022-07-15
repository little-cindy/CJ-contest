#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
struct node{
	int to;
	int next;
}e[400010];
int head[200030];
int tot;
void add(int x,int y){
	tot++;
	e[tot].next=head[x];
	e[tot].to=y;
	head[x]=tot;
}
int co[200030];
int vis[200030];
void color(int x){
	co[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(co[y]==0&&vis[y]==0)
			color(y);
	}
}
int count(){
	int col=0;
	memset(co,0,sizeof(co));
	for(int i=0;i<n;i++){
		if(co[i]==0&&vis[i]==0){
			col++;
			color(i);
		}
	}
	return col;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x!=y){
			add(x,y);
			add(y,x);
		}
	}	
	cout<<count()<<endl;
	k=read();
	for(int i=1;i<=k;i++){
		int a;
		a=read();
		vis[a]=1;
		cout<<count()<<endl;
	}
	return 0;
}
