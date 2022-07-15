#include<bits/stdc++.h>
using namespace std;
int n,m;
int tong[200005];
int fa[200005];
struct node{
	int x,y;
}a[100005],b[100005];
int tot;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int rd(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=m;i++) a[i].x=rd()+1,a[i].y=rd()+1;
	int k=rd();
	for(int i=1;i<=k;i++){
		int t=rd()+1;
		for(int j=1;j<=m;j++) if(a[j].x!=t&&a[j].y!=t) b[++tot]=a[j];
		m=tot;
		for(int j=1;j<=tot;j++) a[j]=b[j];//cout<<1;
		int cnt=0;
		
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=tot;j++) fa[find(a[j].x)]=find(a[j].y);
		for(int j=1;j<=n;j++){
			int e=find(j);
			if(tong[e]==0){
				cnt++;
				tong[e]=1;
			}
		}
		printf("%d\n",cnt-i);
		memset(tong,0,sizeof(tong));
		tot=0;
	}
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

