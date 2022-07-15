#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int>E[N];
int died[N]; int killed[N];
int f[N],ans[N]; 
int getfa(int ret)
{
    if(f[ret]==ret) return ret;
    else return f[ret]=getfa(f[ret]); 
}
int main()
{
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout); 
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ++x; ++y; 
        E[x].push_back(y); 
        E[y].push_back(x);
    }
    int k; scanf("%d",&k);
    for(int i=1;i<=k;++i)
    {
        scanf("%d",&killed[i]); ++killed[i]; 
        died[killed[i]]++;
    }
    int k_=0; 
    for(int i=1;i<=n;++i) if(died[i]) ++k_; 
    for(int i=1;i<=n;++i) f[i]=i;
    int cnt=n-k_;
    for(int i=1;i<=n;++i)
    {
        if(died[i]) continue;
        for(int j=0,len=E[i].size();j<len;++j)
        {
            if(died[E[i][j]]) continue; 
            int f1=getfa(i),f2=getfa(E[i][j]);
            if(f1!=f2)
            {
                f[f1]=f2; --cnt;
            }
        }
    }
    ans[k]=cnt;
    for(int i=k;i>0;--i)
    {
        died[killed[i]]--;
        if(died[killed[i]]==0)
        {
            ++cnt;
            for(int j=0,len=E[killed[i]].size();j<len;++j)
            {
                if(!died[E[killed[i]][j]])
                {
                    int f1=getfa(killed[i]),f2=getfa(E[killed[i]][j]);
                    if(f1!=f2) 
                    {
                        f[f1]=f2; --cnt;
                    }
                }
            }
        }
        ans[i-1]=cnt;
    }
    for(int i=0;i<=k;++i) cout<<ans[i]<<endl;
    return 0; 
}