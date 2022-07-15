#include<bits/stdc++.h>
using namespace std;
int n,p,q;
struct node{
	int c;
	int h;
	int t;
	double co;
}a[40400];
bool cmp(node x,node y){
	return x.co>y.co;
}
int main(){
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].h>>a[i].t;
		a[i].co=a[i].h/a[i].c;
	}
	cin>>q;
	while(q--){
		int x,y;
		int maxn=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(a[i].c>y||a[i].t>x||(a[i].t+p-1)<x) continue;
			maxn+=a[i].h;
			y-=a[i].c;
			cout<<maxn<<endl;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
/*4 4
2 3 2
3 5 1
4 7 2
11 15 5
4
1 3
2 5
2 6
5 14
*/
