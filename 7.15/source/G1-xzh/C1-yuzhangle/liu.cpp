#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int k,sq;
int head[400400];
int tot;
int vis[400400];
int s[400400];
queue<int>q;
struct edge{
	int next;
	int to;
}e[400400];
void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(vis[y]==0){
			dfs(y);
		}
	}
}
void find(){
	ans=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			ans++;
			dfs(i);
		}
	}
}
void clean(){
	while(q.size()){
		q.pop();
	}
}
void bfs(int t){
	vis[t]=1;
		for(int i=head[t];i;i=e[i].next){
			int y=e[i].to;
			if(vis[y]==1) continue;
			if(s[y]==1) continue;
			bfs(y);
	}
}
void change(){
	sq=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if(s[i]==0&&vis[i]==0){
			sq++;
			bfs(i);
		}
	}
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	memset(s,0,sizeof(s));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x!=y){
			add(x,y);
			add(y,x);
		}
	}
	find();
	cout<<ans<<endl;
	cin>>k;
	//cout<<k<<endl;;
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		s[a]=1;
		change();
		cout<<sq<<endl;
	}
	return 0;
}
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7

9
13
0 1
0 3
0 6
1 4
2 1
2 4
3 4
3 5
3 6
5 6
6 7
6 8
7 8
4
*/
