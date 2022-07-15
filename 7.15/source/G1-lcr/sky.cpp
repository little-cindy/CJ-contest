#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=4e5+5,M=805;
int n,a[N],b[N],m,c[N],p,q,d[N],x;
vector<int>v[M];
struct Point{
	int x,y,z;
	friend bool operator<(const Point&A,const Point&B){
		return A.x==B.x?A.y<B.y:A.x<B.x;
	}
};
vector<Point>s;
int main(){
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-(b+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		d[c[i]]++;
	}
	for(p=1;p*p<=n;p++);
	p--;int y=n;
	for(int i=p+1;i<=n;i++){
		d[p]+=d[i];
		y-=(i-p)*d[i];
		d[i]=0;
	}
	for(int i=p,j;i>=1;i--){
		j=y/i;
		if(i>j){
			d[i-1]+=d[i];
			y-=d[i];
			d[i]=0;
			continue;
		}
		if(d[i]>j){
			y-=d[i]-j;
			d[i-1]+=d[i]-j;
			d[i]=j;
		}
		if(x<i*j){
			x=i*j;
			p=i;q=j;
		}
		d[i-1]+=d[i];
		y-=d[i];
		d[i]=0;
	}
	printf("%d\n%d %d\n",x,p,q);
	int pos=1,p2=0;
	for(int i=1;i<=m;i++){
		if(c[i]<p)continue;
		for(int j=pos;j<pos+p;j++)s.push_back({j-pos+1,j%q,b[i]});
	}
	for(int i=1,kk;i<=m;i++){
		if(c[i]>=p)continue;
		kk=c[i];
		for(int j=pos+p2;j<pos+p&&kk;j++,p2++)s.push_back({j-pos+1,j%q,b[i]}),kk--;
		if(p2==p)p2=0,pos++;
		if(kk>0)for(int j=pos+p2;j<pos+p&&kk;j++,p2++)s.push_back({j-pos+1,j%q,b[i]}),kk--;
	}
	sort(s.begin(),s.end());
	int dd=q;
	for(auto i:s){
		printf("%d ",i.z);
		dd--;
		if(dd==0)puts(""),dd=q;
	}
	return 0;
}
