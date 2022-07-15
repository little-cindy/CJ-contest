#include<bits/stdc++.h>
#define MAXN 4002
#define mod 100000007ll
#define ls(x) x<<1
#define rs(x) x<<1|1
#define debug for(int i=1;i<=max_t<<1;i++){printf("tr[%d]\n",i);for(int j:tr[i])printf("id:%d c:%d h:%d t:%d\n",j,a[j].c,a[j].h,a[j].t);puts("");}
using namespace std;
namespace FastIO
{
	char buf[1<<23],*p1,*p2;
	#define reg register
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2))?EOF:*p1++
	inline int read()
    {
        reg int f=1,w=0;reg char ch=gc();
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
        while(ch>='0'&&ch<='9')w=w*10+ch-'0',ch=gc();
        return f*w;
    }
}
using FastIO::read;
int n,p,q,cnt,max_t;
struct shop
{
    int c,h,id,t;
}a[MAXN],now[MAXN];
int dp[MAXN];
vector<int>tr[80002];
inline void update(int l,int r,int s,int t,int p,int k)
{
    if(s>=l&&t<=r)
    {
        tr[p].push_back(k);
        return;
    }
    int mid=s+t>>1;
    if(mid>=l)update(l,r,s,mid,ls(p),k);
    if(mid<r)update(l,r,mid+1,t,rs(p),k);
    return;
}
inline int query(int goal,int s,int t,int p,int b)
{
    for(int i:tr[p])
        now[++cnt]=a[i];
    if(s==t&&t==goal)
    {
        for(int i=1;i<=cnt;i++)
            for(int j=b;j>=now[i].c;j--)
                dp[j]=max(dp[j],dp[j-now[i].c]+now[i].h);
        return dp[b];
    }
    int mid=s+t>>1;
    if(mid>=goal)
        return query(goal,s,mid,ls(p),b);
    else
        return query(goal,mid+1,t,rs(p),b);
}
int main()
{
	freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    n=read(),p=read();
    for(int i=1;i<=n;i++)
    {
        a[i].c=read(),a[i].h=read();
        a[i].t=read();max_t=max(max_t,a[i].t+p-1);
        a[i].id=i;
    }
    for(int i=1;i<=n;i++)
        update(a[i].t,a[i].t+p-1,1,max_t,1,a[i].id);
    q=read();
    for(int i=1;i<=q;i++)
    {
        cnt=0;
        int a=read(),b=read();
        printf("%d\n",query(a,1,max_t,1,b));
    }
    // debug
    // printf("%.2lf\n",clock()/CLOCKS_PER_SEC);
    return 0;
}

//O(q*n^2)