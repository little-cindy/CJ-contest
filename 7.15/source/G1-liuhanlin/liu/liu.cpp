#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
struct way{
    int f,t;
}l[N];
int n,m,s,k,v[N],f[N],h[N],ans[N],c[N];
int find(int x){
    return f[x]^x?f[x]=find(f[x]):x;
}
void add(int x,int y){
    s++;l[s].f=h[x],l[s].t=y;h[x]=s;
}
int main(){
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1,x,y;i<=m;i++){
	scanf("%d%d",&x,&y);x++,y++;
	if(x^y) add(x,y),add(y,x);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
	scanf("%d",&c[i]),c[i]++;
	v[c[i]]=1;
    }
    ans[k]=n-k;
    for(int i=1;i<=n;i++){
	if(!v[i]){
	    for(int j=h[i];j;j=l[j].f){
		if(!v[l[j].t]){
		    int fj=find(l[j].t),fi=find(i);
		    if(fi^fj) ans[k]--,f[fj]=fi;
		}
	    }
	}
    }
    for(int i=k;i>=1;i--){
	v[c[i]]=0;ans[i-1]=ans[i]+1;
	for(int j=h[c[i]];j;j=l[j].f){
	    if(!v[l[j].t]){
		int fj=find(l[j].t),fi=find(c[i]);
		if(fi^fj) ans[i-1]--,f[fj]=fi;
	    }
	}
    }
    for(int i=0;i<=k;i++) printf("%d\n",ans[i]);
    return 0;
}
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7
*/
