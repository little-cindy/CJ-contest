#include<bits/stdc++.h>
using namespace std;
int n,p,q;
int dp[4005];
int c[105],h[105],t[105];
bool vis[105];
int bb(int n,int m){
	for(int i=1;i<=m;i++){
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		for(int j=m;j>=c[i];j--){
			dp[j]=max(dp[j],dp[j-c[i]]+h[i]);
		}
	}
	return dp[m];
}
struct node{
	int a,b;
}query[1005];
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&c[i],&h[i],&t[i]);
	}
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++){
			vis[i]=false;
			if(t[i]<=a&&a<=t[i]+p-1){
				vis[i]=true;
			}
		}
		printf("%d\n",bb(n,b));
	}
	
	return 0;
} 
/*
4 4
2 3 2
3 5 1
4 7 2
11 15 5
4
1 3
2 5
2 6
5 14
*/
