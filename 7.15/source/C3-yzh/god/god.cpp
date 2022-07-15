#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3e5+5;
struct node
{
    int cost,hap,tim;
}e[MAXN];
int n,p,q;
int dp[MAXN];
signed main()
{
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    scanf("%lld%lld",&n,&p);
    for(register int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&e[i].cost,&e[i].hap,&e[i].tim);
    scanf("%lld",&q);
    for(register int i=1;i<=q;i++)
    {
        memset(dp,0,sizeof dp);
        int a,b;
        scanf("%lld%lld",&a,&b);
        vector<node>now;
        for(register int j=1;j<=n;j++)
            if(a>=e[j].tim&&a<=e[j].tim+p-1)now.push_back(e[j]);
        int maxn=0;
        for(register int j=0;j<now.size();j++)
            for(register int k=b;k>=now[j].cost;k--)
            {
                dp[k]=dp[k-now[j].cost]+now[j].hap;
                maxn=max(maxn,dp[k]);
            }
        printf("%lld\n",maxn);
    }
    return 0;
}