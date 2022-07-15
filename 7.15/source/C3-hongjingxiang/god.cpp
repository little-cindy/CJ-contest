#include <bits/stdc++.h>
// #define int long long
using namespace std;

template<typename ...Args>
signed debug(const char* str,Args ...args){return fprintf(stderr,str,args...);}

inline static int read(){
    int s=0;
    bool neg=false;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') neg=true;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return neg?-s:s;
}

struct thing{
    int val,w;
}goods[4005];

struct SegmentTree{
    int dp[4005];
    vector<int> node[80005];
    inline int ls(const int p){return p<<1;}
    inline int rs(const int p){return p<<1|1;}
    
    void update(int p,int l,int r,int nl,int nr,int good){
        if(nl<=l && r<=nr){node[p].push_back(good);return;}
        int mid=(l+r)>>1;
        if(nl<=mid) update(ls(p),l,mid,nl,nr,good);
        if(mid<nr) update(rs(p),mid+1,r,nl,nr,good);
        return;
    }
    
    void query_(int p,int l,int r,int x,int money){
        for(int i:node[p]) for(int j=money;j>=goods[i].w;j--) dp[j]=max(dp[j],dp[j-goods[i].w]+goods[i].val);
        if(l == x && x == r) return;
        int mid=(l+r)>>1;
        if(x<=mid) query_(ls(p),l,mid,x,money);
        else query_(rs(p),mid+1,r,x,money);
        return;
    }
    
    int query(int a,int b){
        query_(1,1,20000,a,b);
        int ans=dp[b]; memset(dp,0,sizeof(int)*(b+1));
        return ans;
    }
}arr;


signed main(){
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    int n=read(),p=read();
    for(int i=1;i<=n;i++){
        goods[i].w=read(),goods[i].val=read();int t=read();
        arr.update(1,1,20000,t,t+p-1,i);
    }
    int q=read();
    while(q--){
        int a=read(),b=read();
        printf("%d\n",arr.query(a,b));
    }
    // system("pause");
    return 0;
}