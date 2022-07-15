#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int N=4005,M=20005;
int n,p,Q,c[N],h[N],t[N],dp[N],ans[M],mx;
vector<pair<int,int> > vec[M];
template<typename T>
inline void read(T &s){
	s=0;bool flag=true;char ch=getchar();
	while(ch!='-' && !isdigit(ch)) ch=getchar();
	if(ch=='-') flag=false,ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	s=(flag?s:-s);return;
}
struct qry{
	int x;
	int y;
	int id;
	bool operator < (const qry &X) const{
		return x<X.x;
	}
}q[M];
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	read(n),read(p);
	for(int i=1;i<=n;i++){
		read(c[i]),read(h[i]),read(t[i]);
		for(int j=t[i];j<t[i]+p;j++)
			vec[j].push_back(make_pair(c[i],h[i]));
	}
	read(Q);
	for(int i=1;i<=Q;i++) read(q[i].x),read(q[i].y),q[i].id=i;
	sort(q+1,q+Q+1);
	for(int i=1;i<=Q;i++){
		if(i==1 || q[i].x!=q[i-1].x) memset(dp,0,sizeof(dp));
		else{
			ans[q[i].id]=dp[q[i].y];continue;
		}
		int xx=q[i].x;
		for(int j=0;j<vec[xx].size();j++)
			for(int k=N-5;k>=vec[xx][j].fir;k--)
				dp[k]=max(dp[k],dp[k-vec[xx][j].fir]+vec[xx][j].sec);
		ans[q[i].id]=dp[q[i].y];
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}

