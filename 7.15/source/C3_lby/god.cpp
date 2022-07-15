#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int h[400010],t[400010];
int dp[410][410];
int w[400010];
int main()
{
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    int N,n,m,x,y,c,a,b,q,p;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&w[i],&h[i],&t[i]);
    }
    scanf("%d",&q);
    for(int k=0;k<q;k++)
    {
        scanf("%d%d",&a,&b);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(j-w[i]>=0&&((a>=t[i])&&(a<=t[i]+p-1)))
                {
                    dp[i][j]=max(dp[i-1][j-w[i]]+h[i],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        printf("%d\n",dp[n][b]);
    }
    return 0;
}