#include<bits/stdc++.h>
using namespace std;
int n,m[4100],p,v[4100],t[4100],a,money,q,f[4100];
int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)cin>>m[i]>>v[i]>>t[i];
	cin>>q;
	for(int k=1;k<=q;k++)
	{
		cin>>a>>money;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		if(a>=t[i]&&a<=t[i]+p-1)
		for(int j=money;j>=m[i];j--)f[j]=max(f[j],f[j-m[i]]+v[i]);
		cout<<f[money]<<endl;
	}
	return 0;
}
