#include<bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int>E[N]; int dep[N],v[N]; long long ans; 
vector<int> dfs(int cur,int fa)
{
    dep[cur]=dep[fa]+1; vector<int>s; s.push_back(v[cur]+dep[cur]); 
    for(int i=0,len=E[cur].size();i<len;++i)
    {
        if(E[cur][i]!=cur)
        {
            vector<int>t=dfs(E[cur][i],cur); 
            for(int j=0,len2=t.size();j<len2;++j) s.push_back(t[j]); 
        }
    } int tie=0;
    for(int i=0,len=s.size();i<len;++i) 
    {
        tie^=(s[i]-dep[cur]); 
    }
    ans+=tie; 
    return s; 
}
int main()
{
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout); 
    int n; scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&v[i]);
    for(int i=2;i<=n;++i) 
    {
        int f; scanf("%d",&f);
        E[f].push_back(i);
    }
    dfs(1,0); 
    printf("%lld\n",ans);
    return 0; 
}