#include<bits/stdc++.h>
using namespace std;
long long n, p, q;
long long c[4005], h[4005], t[4005];
bool o[4005][4005];
long long tt, w[4005], val[4005], dp[4005];
signed main()
{
  	freopen("god.in","r",stdin);
  	freopen("god.out","w",stdout);
	cin>>n>>p;
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i]>>h[i]>>t[i];
	}
	cin>>q;
	for(long long k=1,a,b;k<=q;k++)
	{
		memset(dp,0,sizeof(dp));
		memset(w,0,sizeof(w));
		memset(val,0,sizeof(val));
		tt=0;
		cin>>a>>b;
		for(long long j=1;j<=n;j++)
		{
			if(t[j]<=a&&a<=t[j]+p-1)
			{
				tt++;
				w[tt]=c[j];
				val[tt]=h[j];
			}
		}
		for(long long i=1;i<=tt;i++)
			for(long long j=b;j>=w[i];j--)
				dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
		cout<<dp[b]<<endl;
	}
	return 0;
}

