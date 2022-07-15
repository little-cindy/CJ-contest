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
int n;
int a[525020];
struct edge{
	int to;
	int next;
}e[1050050];
int head[525020];
int tot;
void add(int x,int y){
	tot++;
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
queue <int> q;
int d[525020];
int t;
int val[525020];
int f[525020][20];
void bfs(){
	d[1]=1;
	q.push(1);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].to;
			if(d[y])continue; 
			d[y]=d[x]+1;
			f[y][0]=x;
			for(int j=1;j<=t;j++)
				f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}
int ans;
void count(int x){
	for(int i=0;i<=t;i++){
		if(f[x][i]==0)break;
		int sum=a[x]+d[x]-d[f[x][i]];
		val[f[x][i]]=(val[f[x][i]]^sum);
	//	cout<<sum<<" ";
	}
	//cout<<endl;
}
int main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	n=read();
	t=log2(n);
	for(int i=1;i<=n;i++){
		a[i]=read();
		val[i]=a[i];
	}
	for(int i=2;i<=n;i++){
		int x;
		x=read();
		add(i,x);
		add(x,i);
	}
	bfs();
	for(int i=1;i<=n;i++){
		count(i);		
	//	cout<<endl;	
	}
	for(int i=1;i<=n;i++)
		ans+=val[i];
	cout<<ans;
	return 0;
} 
