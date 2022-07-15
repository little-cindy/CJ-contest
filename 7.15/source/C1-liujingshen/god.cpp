#include<bits/stdc++.h>
using namespace std;
int n,f[1005][4005],p,cnt,t;
struct node{
	int c,h,t;
}a[105],q[105];
int dp(int b,int k){
	for(int i=1;i<=cnt;i++)
		for(int j=b;j>=q[i].c;j--)
			f[k][j]=max(f[k][j],f[k][j-q[i].c]+q[i].h);
	int ans=0;
	for(int i=1;i<=b;i++)
		ans=max(ans,f[k][i]);
	return ans;
}
void find(int x){
	cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i].t<=x&&a[i].t+p>x)
			q[++cnt]=a[i];
}
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i].c>>a[i].h>>a[i].t;
	cin>>t;
	for(int i=1,a,b;i<=t;i++){
		cin>>a>>b;
		find(a);
		cout<<dp(b,i)<<endl;
	}
	return 0;
}
