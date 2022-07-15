#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[500001],qz[500001],hz[500001],cnt=0,jz[500001],ans,ans2;
struct no
{
	ll sum,as;
	friend bool operator<(no a,no b)
	{
		return a.as<b.as;
	}
}d[500001];
void inline r(ll &x)//ÎÞ¸ºÊý
{
   x=0;
   char c=getchar();
   while(c<'0'||c>'9')
   c=getchar();
   while(c>='0'&&c<='9')
   {
	 x=(x<<1)+(x<<3)+(c^48);
	 c=getchar();
   }
}
void inline pri(ll xx)
{
	if(xx>9)
	pri(xx/10);
	ll x=xx%10;
	putchar(x+48);
}
int main()
{
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	 r(n);
	 for(int i=1;i<=n;i++)r(a[i]);
	 sort(a+1,a+n+1);
	 for(int i=1;i<=n;i++)
	 if(a[i]!=a[i-1])
	 {++cnt;d[cnt].sum=a[i];d[cnt].as=1;}
	 else
	 d[cnt].as++;
	 sort(d+1,d+cnt+1);
	 //cout<<d[1].as<<" "<<d[2].as<<endl;
	 for(int i=cnt;i>=1;i--)hz[i]=hz[i+1]+d[i].as;
	 for(int i=1;i<=cnt;i++)qz[i]=qz[i-1]+d[i].as;
	 ll j=1;
	 for(ll i=1;i<=n;i++)
	 {
	 	while(j<=cnt&&d[j].as<=i)
	 	j++;
	 	j--;
	 	if((cnt-j)*i+qz[j]>=i*i)
	 	ans=((cnt-j)*i+qz[j])/i,ans2=i;
	 }
	 printf("%lld\n",ans2*ans);
	 printf("%lld %lld\n",ans2,ans);
	// for(int i=1;i<=ans2;i++)
	 ll ii=1,jj=1,ttt=1;
	   for(ll j=cnt;j>=1;j--)
	     {
	     	ll qq=d[j].as-ans2;
	     	qq=max(qq,(ll)0);
	     	while(d[j].as>qq)
	     	{
	     	if(jj>ans)
	     	jj-=ans;
	     	if(ii>ans2)
	     	{ii-=ans2,++ttt;jj=ttt;}
	     	if(jz[((ii-1)*ans+jj)]!=0)
	     	break;
	     	jz[(ii-1)*ans+jj]=d[j].sum;
	     	ii++,jj++;
	     	d[j].as--;
	    	}
	    	if(jj>ans)
	     	jj-=ans;
	     	if(ii>ans2)
	     	{ii-=ans2,++ttt;jj=ttt;}
	    	if(jz[((ii-1)*ans+jj)]!=0)
	     	break;
		 }
	for(ll i=1;i<=ans2*ans;i++)
	if(i%ans==0)
	{pri(jz[i]);putchar('\n');}
	else
	{pri(jz[i]);putchar(' ');}
}
