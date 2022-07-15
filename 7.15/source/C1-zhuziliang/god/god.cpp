#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,p,bb[5001],ttt,ccntt=1,fk[5001],ma=0,iii=1,jjj=1,q;
struct nno
{
	ll a,b;
	friend bool operator<(nno a,nno b)
	{
		return a.a<b.a;
	}
}pr[40001];
struct no
{
	ll c,h,t;
	friend bool operator<(no a,no b)
	{
		return a.t<b.t;
	}
}rp[5001];
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
int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	r(n);r(p);
	for(int i=1;i<=n;i++)
	{r(rp[i].c);r(rp[i].h);r(rp[i].t);}
	sort(rp+1,rp+n+1);
	r(q);
	ttt=sqrt(n);
	for(int i=1;i<=q;i++)
    {r(pr[i].a);r(pr[i].b);ma=max(ma,pr[i].b);}
	sort(pr+1,pr+q+1);
//	for(int i=1;i<=cnt;i++)
//	{
//		if(i/ttt!=(i-1)/ttt)
//		ccntt++;
//		for(int i=ma;i>=1;i--)
//		fk[ccntt]=max(fk[ccntt],fk[ccntt-rp[i].c]+rp[i].h);
	//}
	for(int i=1;i<=q;i++)
	{
		memset(bb,0,sizeof(bb));
		ll ans=0;
	   while(iii<=n&&rp[iii].t+p-1<pr[i].a)
	   iii++;
	   while(jjj<=n&&rp[jjj].t<=pr[i].a)
	   jjj++;
	   jjj--;
	   for(int j=iii;j<=jjj;j++)
	   for(int ii=ma;ii>=rp[j].c;ii--)
	   bb[ii]=max(bb[ii],bb[ii-rp[j].c]+rp[j].h);
	   for(int j=1;j<=pr[i].b;j++)
	   ans=max(ans,bb[j]);
	   cout<<ans<<endl;
	}
}
