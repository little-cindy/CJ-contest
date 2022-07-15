#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,sum;
}d[400005];
int n,a[400005],cnt,os[400005];
vector<int> nbr[400005],flag[400005];
void work(int x)
{
	int less=0;
	for(int i=1;i<=cnt;i++)
		less+=min(x,d[i].sum);
	int y=less/x;
	cout<<x*y<<endl;
	cout<<x<<" "<<y<<endl;
	less=x;
	int cnt2=0;
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=min(min(x,y),d[i].sum);j++)
			os[++cnt2]=d[i].num;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			nbr[i].push_back(0);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			flag[i].push_back(0);
//	for(int i=1;i<=n;i++)
//		cout<<os[i]<<" ";
	cnt2=0;
	int vis=0;
	for(int i=0,j=0;;i=(i+1)%x,j=(j+1)%y){
//		cout<<i<<" "<<j<<endl;
		if(flag[i][j]==1){
			i=(i+1)%x;
			if(flag[i][j]==1){
				vis=1;
				break;	
			}
		}
		nbr[i][j]=os[++cnt2];
		flag[i][j]=1;
	}
	for(int i=0;i<x;i++,cout<<endl)
		for(int j=0;j<y;j++)
			cout<<nbr[i][j]<<" ";
}
int main()
{
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]!=a[i])
			d[++cnt].num=a[i];
		d[cnt].sum++;
	}
	int l=0,r=cnt+1;
//	for(int i=1;i<=cnt;i++)
//		cout<<d[i].num<<" "<<d[i].sum<<endl;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		int x=mid;
		int less=0;
		for(int i=1;i<=cnt;i++)
			less+=min(x,d[i].sum);
		int y=less/x;
//		cout<<x<<" "<<y<<" "<<less<<" "<<l<<" "<<r<<endl;
		y=min(y,cnt);
		if(x<=y)
			l=mid;
		else
			r=mid;
	}
	work(l);
    return 0;
}

