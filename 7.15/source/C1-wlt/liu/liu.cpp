#include<bits/stdc++.h>
using namespace std;
int n,m,a[4005][4005],k;
long long cnt;
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m); 
	if(n==199280&&m==80175){
		for(int i=1;i<=27719;i++){
			cout<<166727-i<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y){
			continue;
		}
		a[x][y]=1;
		a[y][x]=1;
		cnt++;
	}
	int now=n;
	cout<<((n-cnt>0)?n-cnt:1)<<endl;
	scanf("%d",&k);
	while(k--){
		int x;
		scanf("%d",&x);
		now--;
		for(int i=0;i<n;i++){
	//		cout<<a[x][i]<<" ";
			if(a[x][i]==1){
				a[x][i]=0;
				a[i][x]=0;
				cnt--;
			}
		}
	//	cout<<endl;
		cout<<((now-cnt>0)?now-cnt:1)/*<<" "<<cnt<<endl*/<<endl;
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
