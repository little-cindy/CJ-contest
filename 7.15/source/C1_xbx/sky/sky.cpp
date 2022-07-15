//Light Know Right is so CUTE. 
#include<bits/stdc++.h>

using namespace std;

const int N=55;

int w[N];
int n;
int a[N];
int ans[N][N];
bool vis[N];
int nn,hang,lie,cnt=0;
bool ha[N][N],li[N][N];

int main(){
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<'\n'<<1<<' '<<n<<'\n';
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}
