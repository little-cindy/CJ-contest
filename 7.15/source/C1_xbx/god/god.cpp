#include<bits/stdc++.h>

using namespace std;

const int N=2e4+5;

struct Node{
	int c,h,t;
}Q[N];
int n,p;
int w[N<<1],v[N<<1];
int f[N<<1];

int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>Q[i].c>>Q[i].h>>Q[i].t;
	}
	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;
		int cnt=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			if(a>=Q[i].t&&a<=Q[i].t+p-1) w[++cnt]=Q[i].c,v[cnt]=Q[i].h;
		}
		for(int i=1;i<=cnt;i++){
			for(int j=b;j>=w[i];j--){
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			}
		}
		cout<<f[b]<<'\n';
	}
	return 0;
}
