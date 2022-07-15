#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();int s=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
int n,p,q,day[4010][50010],c[50010],h[50010],t[50010],dp[50010];
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	n=read();p=read();
	for(int i=1;i<=n;i++){
		c[i]=read(),h[i]=read(),t[i]=read();
		for(int j=t[i];j<=t[i]+p-1;j++)
			day[i][j]=1;
	}
	q=read();
	while(q--){
		int a=read(),b=read();
		memset(dp,0,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=b;j>=c[i];j--)
				if(day[i][a])
					dp[j]=max(dp[j-c[i]]+h[i],dp[j]);
		printf("%d\n",dp[b]);
	}
	return 0;
}
