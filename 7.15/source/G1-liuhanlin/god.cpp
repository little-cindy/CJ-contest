#include<bits/stdc++.h>
using namespace std;
const int N=4615;
int n,p,d[N],w[N],v[N],t[N],q;
int main(){
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&w[i],&v[i],&t[i]);
    scanf("%d",&q);
    while(q--){
	int a,b;scanf("%d%d",&a,&b);
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	    if(t[i]<=a&&a<=t[i]+p-1)
		for(int j=b;j>=w[i];j--) d[j]=max(d[j],d[j-w[i]]+v[i]);
	printf("%d\n",d[b]);
    }
    return 0;
}
