#include<bits/stdc++.h>
using namespace std;
int n,p,q;
int tot;
int dp[4005][4005];
struct node{
	int c;
	int h;
	int t;
	int to;
}a[4005],b[4005];
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
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	n=rd(),p=rd();
	for(int i=1;i<=n;i++){
		a[i].c=rd();a[i].h=rd(),a[i].t=rd();
		a[i].to=a[i].t+p-1;
		//cout<<a[i].to<<"_"<<endl;
	}
	q=rd();
	while(q--){
		int x=rd(),y=rd();
		memset(dp,0,sizeof(dp));
		int minn=100000007;
		for(int i=1;i<=n;i++){
			if(a[i].t<=x&&a[i].to>=x) b[++tot]=a[i],minn=min(minn,a[i].c);
		}
		if(y<minn) printf("0\n");
		for(int i=1;i<=n;i++) dp[0][i]=0,dp[i][0]=0;
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=y;j++){
				dp[j][i]=dp[j][i-1];
				if(j>=b[i].c) dp[j][i]=max(dp[j][i],dp[j-b[i].c][i-1]+b[i].h);
			}
		}
		printf("%d\n",dp[y][tot]);
		tot=0;
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


