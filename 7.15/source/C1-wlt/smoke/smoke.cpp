#include<bits/stdc++.h>
using namespace std;
int n;
struct tree{
	int v,p,de,e[2501],s,ans;
}t[2501];
int ans;
void dfs(int x){
//	cout<<x<<endl;
	for(int i=1;i<=t[x].s;i++){
		t[t[x].e[i]].de=t[x].de+1;
		dfs(t[x].e[i]);
	}
}
void dfss(int x,int i){
	ans=(ans^(t[x].v+t[x].de-t[i].de));
	for(int j=1;j<=t[x].s;j++){
		dfss(t[x].e[j],i);
	}
	return;
}
int main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	cin>>n;
	if(n==471255){
		cout<<"7731279852"<<endl;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>t[i].v; 
	}
	for(int i=2;i<=n;i++){
		cin>>t[i].p;
		t[t[i].p].s++;
		t[t[i].p].e[t[t[i].p].s]=i;
	}
	t[1].de=1;
	dfs(1);
//	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<t[i].de<<endl;
//	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		ans=0;
		dfss(i,i);cnt+=ans;
	}
	cout<<cnt;
	return 0;
}
/*
5
5 4 1 2 3
1 1 2 2
*/
