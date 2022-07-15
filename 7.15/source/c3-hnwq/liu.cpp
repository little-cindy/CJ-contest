#include<bits/stdc++.h>
#define gc getchar
using namespace std;
const int N=2e5+5;
struct tN
{
    int a,b;
}e[N];
int fa[N<<1],wd[N<<1];
// int de[N<<1];
int an[N<<1];
int ged(tN o)
{
    return max(wd[o.a],wd[o.b]);
}
bool cmp(tN x,tN y)
{
    if(ged(x)!=ged(y)) return ged(x)<ged(y);
    if(x.a!=y.a) return x.a<y.a;
    return x.b<y.b;
}
int fif(int o)
{
    if(fa[o]==o) return o;
    return fa[o]=fif(fa[o]);
}
void merge(int x,int y)
{
    int fx=fif(x),fy=fif(y);
    fa[fx]=fy;
}
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
int main()
{
    int n,m,k;
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        wd[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        e[i].a=read()+1;
        e[i].b=read()+1;
    }
    k=read();
    for(int i=k;i;i--)
    {
        int in=read()+1;
        // de[i]=in;
        wd[in]=i;
    }
    sort(e+1,e+m+1,cmp);
    int ans=n-k,i=1;
    while(ged(e[i])==0&&i<=m)
    {
        if(fif(e[i].a)!=fif(e[i].b))
        {
            // cout<<e[i].a<<' '<<e[i].b<<endl;
            ans--;
            merge(e[i].a,e[i].b);
        }
        i++;
    }
    an[k]=ans;
    for(int j=1;j<=k;j++)
    {
        ans++;
        while(ged(e[i])==j&&i<=m)
        {
            if(fif(e[i].a)!=fif(e[i].b))
            {
                ans--;
                merge(e[i].a,e[i].b);
            }
            i++;
            // cout<<fif(e[i].a)<<' '<<fif(e[i].b)<<' '<<ged(e[i])<<endl;
        }
        // cout<<j<<endl;
        an[k-j]=ans;
    }
    for(int i=0;i<=k;i++) printf("%d\n",an[i]);
    return 0;
}