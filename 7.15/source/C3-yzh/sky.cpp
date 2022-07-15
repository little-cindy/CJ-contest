#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=4e5+5;
struct node
{
    int val,id;
}e[MAXN];
inline bool cmp(node a,node b)
{
    return a.val<b.val;
}
int n,len,ans,tot,nx,ny,x,y;
int a[MAXN],v[MAXN],A[MAXN],val[MAXN],sum[MAXN];
int sum1[MAXN],f[MAXN],bef[MAXN];
vector<int>res[MAXN];
signed main()
{
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    scanf("%lld",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        A[i]=a[i];
    }
    sort(A+1,A+n+1);
    for(register int i=1;i<=n;i++)
    {
        int op=lower_bound(A+1,A+n+1,a[i])-A;
        bef[op]=a[i];
        a[i]=op;
        v[a[i]]++;
    }
    vector<int>V;
    for(register int i=1;i<=n;i++)
        if(v[i])V.push_back(v[i]);
    memset(v,0,sizeof v);
    for(register int i=0;i<V.size();i++)
        v[V[i]]++;
    for(register int i=n;i>=1;i--)
        sum[i]=sum[i+1]+v[i];
    for(register int i=1;i<=n;i++)
        sum1[i]=sum1[i-1]+i*v[i];
    for(register int i=1;i<=n;i++)
        for(register int j=i*i;j<=n;j+=i)
            f[j]=i;
    for(register int i=1;i<=n;i++)
    {
        int val=f[i];
        if(sum[val+1]*val+sum1[val]>=i)ans=i; 
    }
    memset(v,0,sizeof v);
    for(register int i=1;i<=n;i++)
        v[a[i]]++;
    for(register int i=1;i<=n;i++)
    {
        v[i]=min(v[i],f[ans]);
        e[++tot].id=i;
        e[tot].val=v[i];
    }
    sort(e+1,e+tot+1,cmp);
    x=f[ans],y=(ans/f[ans]),nx=1,ny=1;
    for(register int i=1;i<=x;i++)
        for(register int j=0;j<=y;j++)
            res[i].push_back(0);
    for(register int i=n;i>=1;i--)
        for(register int j=1;j<=e[i].val;j++)
        {
            res[nx][ny]=e[i].id;
            if(nx!=x)
            {
                nx++,ny++;
                if (ny>y)ny-=y;
            }
            else
            {
                int _ny=ny-(nx-1);
                if (_ny<=0)_ny+=y;
                nx=1,ny=_ny+1;
            }
        }
    printf("%lld\n%lld %lld\n",ans,x,y);
    for(register int i=1;i<=x;i++)
    {
        for(register int j=1;j<=y;j++) 
            printf("%lld ",bef[res[i][j]]);
        puts("");
    }
    return 0;
} 