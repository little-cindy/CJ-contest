#include<bits/stdc++.h>
using namespace std;
int n,ans;
int v[525010],val[525010];
int read(){
	int x=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void ti(){
	val[n]=v[n];
	for(int i=1;i<n;i++){ 
		val[i]=v[n]+n-i;
		for(int j=i;j<n;j++){
			val[i]=val[i]^(v[j]+j-i);
		}
	}
}
int main(){
	freopen("smoke.in","r",stdin);
	freopen("smoke.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int fl=0;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		if(x!=(i-1)) fl=1;
	}
	if(fl==0){
		ti();
		for(int i=1;i<=n;i++){
			ans+=val[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
} 
/*10
7 5 3 9 10 2 44 2 1 9 
1 2 3 4 5 6 7 8 9
33
33
32
28
41
34
32
11
11
9
*/
