#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5,K=1005;
int n,a[N],b[N],cntt[N],siz,maxn,num,ans[N][5],cnt;
template<typename T>
inline void read(T &s){
	s=0;bool flag=true;char ch=getchar();
	while(ch!='-' && !isdigit(ch)) ch=getchar();
	if(ch=='-') flag=false,ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	s=(flag?s:-s);return;
}
int main(){
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	read(n);num=n;
	for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);siz=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+siz+1,a[i])-b;
		cntt[a[i]]++;
	}
	for(int i=1;i<=siz;i++){
		if(1ll*cntt[i]*cntt[i]>n){
			num-=(int)(sqrt(n))-cntt[i];
			cntt[i]=sqrt(n);
		}
		maxn=max(maxn,cntt[i]);
	}
	if(maxn==1){
		printf("%d\n%d %d\n",num,1,num);
		for(int i=1;i<=siz;i++)
			if(cntt[i]) printf("%d ",i);
		return 0;
	}
	if(maxn==2){
		num=num/2*2;
		printf("%d\n%d %d\n",num,2,num/2);
		for(int i=1;i<=siz;i++)
			if(cntt[i]==2) ans[cnt][0]=ans[++cnt][1]=i;
		for(int i=1;i<=siz;i++)
			if(cntt[i]==1){
				if(ans[cnt][1]) cnt++;
				if(!ans[cnt][0]) ans[cnt][0]=i;
				else ans[cnt][1]=i;
			}
		for(int i=1;i<=num;i++)
			swap(ans[i-1][0],ans[i][0]);ans[siz][0]=ans[0][0];
		for(int i=0;i<=1;i++,printf("\n"))
			for(int j=1;j<=num/2;j++)
				printf("%d ",ans[j][i]);
	}
	return 0;
}

