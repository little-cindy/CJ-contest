#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int r=0,f=1;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-')f=0;
        c=getchar();
    }
    while(isdigit(c))
    {
        r=(r<<1)+(r<<3)+c-48;
        c=getchar();
    }
    return f?r:-r;
}

const int N=4e3+5;
int n,p,b,q;
struct node
{
    int g,h,t;
}a[N];

bool cmp(node x,node y)
{
    return x.t<y.t;
}

struct query
{
    int t,bb,id;
}que[N];

bool cmp2(query x,query y)
{
    return x.t<y.t;
}
int dp[40005];
int ans[40005];
signed main()
{
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    n=read(); p=read();
    for(int i=1;i<=n;i++)
    {
        a[i].g=read();
        a[i].h=read();
        a[i].t=read();
    }
    sort(a+1,a+1+n,cmp);
    q=read();
    for(int i=1;i<=q;i++)
    {
        que[i].t=read();
        que[i].bb=read();
        que[i].id=i;
    }
    sort(que+1,que+1+n,cmp2);
    int l=1,r=1;
    for(int i=1;i<=q;i++)
    {
        while(r<=n&&a[r].t<=que[i].t)
            r++;
        while(l<r&&(a[l].t<=que[i].t-p))
            l++;
        for(int j=l;j<r;j++)
            for(int k=que[i].bb-a[j].g;k>=0;k--)
                dp[k+a[j].g]=max(dp[k+a[j].g],dp[k]+a[j].h);
        for(int k=0;k<=que[i].bb;k++)
            ans[que[i].id]=max(ans[que[i].id],dp[k]),dp[k]=0;
    }
    for(int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}