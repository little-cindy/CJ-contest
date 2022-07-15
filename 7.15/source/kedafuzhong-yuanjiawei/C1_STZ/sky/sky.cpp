#include<bits/stdc++.h>
using namespace std;
int n;
int a[25];
int matrix[25][25];
int as[25][25];
int ansn,ansm;
bool vis[25];
void dfs(int nowx,int nowy,int N,int m){
	if(nowx>N){
		if(N*m>ansn*ansm){
			ansn=N,ansm=m;
			for(int i=1;i<=N;i++){
				for(int j=1;j<=m;j++){
					as[i][j]=matrix[i][j];
				}
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bool tag=false;
			for(int j=1;j<nowx;j++){
				if(matrix[j][nowy]==a[i]){
					tag=true;
					break;
				}
			}
			for(int j=1;j<nowy;j++){
				if(matrix[nowx][j]==a[i]){
					tag=true;
					break;
				}
			}
			if(tag)continue;
			vis[i]=true;
			matrix[nowx][nowy]=a[i];
			if(nowy<m)dfs(nowx,nowy+1,N,m);
			else dfs(nowx+1,1,N,m);
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int x=1;x<=n;x++){
		for(int y=1;x*y<=n;y++){
//			printf("%d %d\n",x,y);
			dfs(1,1,x,y);
		}
	}
	printf("%d\n",ansn*ansm);
	printf("%d %d\n",ansn,ansm);
	for(int i=1;i<=ansn;i++){
		for(int j=1;j<=ansm;j++){
			printf("%d ",as[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
12
3 1 4 1 5 9 2 6 5 3 5 8
*/
