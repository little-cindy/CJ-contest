#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;

inline int read()
{
    register int x=0,f=1;
    register char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int n;
int a[MAXN];
int vis[MAXN];
int s[MAXN];
int m;

inline void dist()
{
    sort(s+1,s+n+1);
    m=unique(s+1,s+n+1)-s-1;
    for(register int i=1;i<=n;i++)
        a[i]=lower_bound(s+1,s+m+1,a[i])-s;
}

struct Node
{
    int cnt,id;
};

int len,wid;
vector< pair<int,int> >V;
vector<int>num;
vector<vector<int>>ans;

int main()
{
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    n=read();
    for(register int i=1;i<=n;i++)
    {
        a[i]=read();
        s[i]=a[i];
    }
    dist();
    for(register int i=1;i<=n;i++)  
        vis[a[i]]++;
    for(register int i=1;i<=m;i++)
        V.push_back(make_pair(vis[i],i));
    sort(V.begin(),V.end());
    int anss=0;
    for(register int i=1;i*i<=n;i++)//枚举长
    {
        int ansss=0;
        for(auto j:V)
        {
            ansss+=min(j.first,i);
        }
        if(ansss/i<i)
            continue;
        if(ansss>anss)
        {
            anss=ansss;
            len=i,wid=ansss/i;
        }
    }
    printf("%d\n%d %d\n",anss,len,wid);
    reverse(V.begin(),V.end());
    for(auto i:V)
        for(register int j=1;j<=min(len,i.first);j++)
            num.push_back(i.second);
    ans.resize(len);
    for(register int i=0;i<len;++i) 
        ans[i].resize(wid);
    for(register int i=0,x=0,y=0;i<anss;++i) 
    {
        ans[x][y]=num[i]; 
        x++;
        y++;
        if(x==len)
        {
            x=0;
            y-=len-1;
        }
        if(y<0)
            y+=wid;
        if(y>=wid)
            y-=wid;
    }
    for(register int i=0;i<len;i++) 
    {
        for(register int j=0;j<wid;j++) 
            printf("%d ",s[ans[i][j]]);
        puts("");
    }
    return 0;
}