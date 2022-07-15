#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
struct num{
    int b,w;
}c[N];
int n,a[N],s,ts=1e8;
int main(){
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int t=0;
    for(int i=1;i<=n;i++){
	t++;
	if(a[i]^a[i+1]){
	    s++;c[s].w=t;
	    ts=min(ts,t);
	    t=0;c[s].b=a[i];
	}
    }
    if(s*s<=n&&ts>=s){
	printf("%d\n%d %d\n",s*s,s,s);
	for(int i=1;i<=s;i++){
	    for(int j=1;j<=s;j++)
		printf("%d ",c[(i+j-1)%s+1].b);
	    puts("");
	}
	return 0;
    }
    if(s*s<=n){
	printf("%d\n%d %d\n",ts*s,ts,s);
	for(int i=1;i<=ts;i++){
	    for(int j=1;j<=s;j++)
		printf("%d ",c[(i+j-1)%s+1].b);
	    puts("");
	}
	return 0;
    }
    
    return 0;
}
