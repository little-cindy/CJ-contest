#include<bits/stdc++.h>
#define gc getchar
using namespace std;
const int N=4e5+5;
struct tN
{
    int a,s;
}p[N];
int read()
{
    int o=0,f=1;
    char ch=gc();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(ch<='9'&&ch>='0')
    {
        o=(o<<3)+(o<<1)+ch-'0';
        ch=gc();
    }
    return o*f;
}
int n,mn,a[N],c1[N],c2[N];
int lb(int o)
{
    return o&(-o);
}
void xg(int l,int r)
{
    for(int i=l;i<=mn;i+=lb(i))
    {
        c1[i]+=1;
        c2[i]+=l;
    }
    for(int i=r+1;i<=mn;i+=lb(i))
    {
        c1[i]-=1;
        c2[i]-=r+1;
    }
}
int xw(int l,int r)
{
    int s1=0,s2=0;
    for(int i=r;i;i-=lb(i))
    {
        s1+=c1[i];
        s2+=c2[i];
    }
    for(int i=l-1;i;i-=lb(i))
    {
        s1-=c1[i];
        s2-=c2[i];
    }
    s1=(r+1)*s1-s2;
    return s1;
}
vector< vector<int> > ans;
int main()
{
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    a[0]=0;
    int ns=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            mn=max(mn,p[ns++].s);
            p[ns].a=a[i];
            p[ns].s=0;
        }
        p[ns].s++;
    }
    mn=max(mn,p[ns].s);
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(int i=1;i<=ns;i++) xg(1,p[i].s);
    int u=(int)floor(sqrt(n*1.0)),anp=0,anq=0;
    for(int i=u;i;i--)
    {
        int o=xw(1,i);
        if((o/u)*u>anp*anq)
        {
            anp=u;
            anq=o/u;
        }
    }
    printf("%d\n",anp*anq);
    printf("%d %d\n",anp,anq);
    ans.resize(anq+5);
    for(int i=1;i<=anq;i++) ans[i].resize(anp+5);
    int o=__gcd(anp,anq),x=1,y=1;
    if(anp==2&&anq==2)
    {
        if(p[2].s>=2)
        {
            printf("%d %d\n",p[1].a,p[2].a);
            printf("%d ",p[2].s);
            if(p[1].s>=2)
            {
                printf("%d\n",p[1].a);
            }
            else printf("%d\n",p[3].a);
            return 0;
        }
    }
    int j=1,k=1;
    for(int i=1;i<=o;i++)
    {
        x=i;
        y=1;
        for(;!ans[x][y];k++)
        {
            if(k>min(p[j].s,anp))
            {
                j++;
                k=1;
            }
            ans[x][y]=p[j].a;
            x=(x%anq)+1;
            y=(y%anp)+1;
        }
    }
    for(int i=1;i<=anp;i++)
    {
        for(int j=1;j<=anq;j++) printf("%d ",ans[j][i]);
        printf("\n");
    }
    return 0;
}