#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
int n,a[N],fa[N],ans[N];
ll res;
template<typename T>
inline void read(T &s){
	s=0;bool flag=true;char ch=getchar();
	while(ch!='-' && !isdigit(ch)) ch=getchar();
	if(ch=='-') flag=false,ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	s=(flag?s:-s);return;
}
int main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) read(fa[i]);
	for(int i=1;i<=n;i++)
		for(int j=i,k=0;j;j=fa[j],k++)
			ans[j]^=(a[i]+k);
	for(int i=1;i<=n;i++) res+=ans[i];
	printf("%lld",res);return 0;
}

