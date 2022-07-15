#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    freopen("sky.out","r",stdin);
    int sum,n,m;
    cin>>sum>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) 
        {
            cin>>a[i][j]; 
        }
    }
    for(int i=1;i<=n;++i)
    {
        set<int>s;s.clear(); 
        for(int j=1;j<=m;++j)
        {
            
            if(s.find(a[i][j])!=s.end())
            {
                puts("fake"); return 0; 
            }
            else s.insert(a[i][j]); 
        }
    }
    for(int i=1;i<=n;++i)
    {
        set<int>s; s.clear();
        for(int j=1;j<=m;++j) 
        {
            if(s.find(a[j][i])!=s.end()) {puts("fake"); return 0; }
            else s.insert(a[j][i]); 
        }
    }
    puts("ok");
    return 0; 
}