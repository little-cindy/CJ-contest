#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
vector<int>e[MAXN];
int fa[MAXN];
int n,m,k;
inline int find(int x)
{
    if(x==fa[x])return fa[x];
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
bitset<MAXN>des;
int d[MAXN];
int pt[MAXN];
int main()
{
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;i++)
        fa[i]=i;
    for(register int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    scanf("%d",&k);
    for(register int i=k;i>=1;i--)
    {
        scanf("%d",&d[i]);
        d[i]++;
        des[d[i]]=1;
    }
    int ans=n-k;
    for(register int i=1;i<=n;i++) 
        for(register int j=0;j<e[i].size();j++)
        {
            int y=e[i][j];
            if(!des[i]&&!des[y])
            {
                if(find(i)==find(y))continue;
                merge(i,y);
                ans--;
            }
        }
    pt[k+1]=ans;
    for(register int i=1;i<=k;i++)
    {
        ans++;
        des[d[i]]=0;
        for(register int j=0;j<e[d[i]].size();j++)
        {
            int y=e[d[i]][j];
            if(!des[d[i]]&&!des[y])
            {
                if(find(d[i])==find(y))continue;
                merge(d[i],y);
                // cout<<d[i]<<" "<<y<<endl;
                ans--;
            }
        }
        pt[k-i+1]=ans;
    }
    for(register int i=1;i<=k+1;i++)
        printf("%d\n",pt[i]);
    return 0;
}