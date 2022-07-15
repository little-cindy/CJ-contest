#include<bits/stdc++.h>
using namespace std;template<typename T>void read(T&x){
	x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-1;
	do x=x*10+c-'0';while(isdigit(c=getchar()));x*=f;
}
template<typename T,typename...O>void read(T&x,O&...o){read(x),read(o...);}
const int N=4e5+5;int n,a[N];
int main(){
	freopen("sky.in","r",stdin),freopen("sky.out","w",stdout);
	read(n);for(int i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+1+n),n=unique(a+1,a+1+n)-a-1;
	cout<<n<<endl<<"1 "<<n<<endl;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}
