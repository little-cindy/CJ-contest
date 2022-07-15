#include<bits/stdc++.h>
using namespace std;
int n,p,q,dp[4002],c[4002],h[4002],t[4002],f[4002];
int ans;
void dfs(int no,int cn,int hn){
//	cout<<no<<" "<<cn<<" "<<hn<<" "<<ans<<endl;
	if(no==n+1||cn==0){
		ans=max(ans,hn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0||cn-c[i]<0){
			dfs(no+1,cn,hn);
			continue;
		}
		f[i]=0;
		dfs(no+1,cn-c[i],hn+h[i]);
		f[i]=1;
	}
}
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>h[i]>>t[i];
	}
	cin>>q;
	while(q--){
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			if(a>=t[i]&&a<=t[i]+p-1){
//				cout<<i<<" ";
				f[i]=1;
			}
		}
		if(n<=15){
			ans=0;
			dfs(1,b,0);
			cout<<ans<<endl;
		}
		else{
			dp[0]=0;
			for(int i=1;i<=b;i++){
				for(int j=1;j<=n;j++){
					if(f[j]==0||i<c[j]){
						continue;
					}
					dp[i]=max(dp[i-c[j]]+h[j],dp[i]);
				}
			//	cout<<dp[i]<<" ";
			}
	//		cout<<endl;
			cout<<dp[b]<<endl;
		}
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

5
8
10
18

*/
