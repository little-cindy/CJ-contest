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

int val[10005];
struct Edge{
    int v,nxt;
}e[10005];
int head[10005],ecnt;

void add(int u,int v){
    ecnt++;
    e[ecnt].v=v;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
    return;
}

int dfs(int now,int dis){
    int res=val[now]+dis;
    for(int i=head[now];i;i=e[i].nxt){
        int v=e[i].v;
        res^=dfs(v,dis+1);
    }
    return res;
}

signed main(){
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=2;i<=n;i++) add(read(),i);
    int ans=0;
    for(int i=1;i<=n;i++) ans+=dfs(i,0);
    printf("%d",ans);
    // system("pause");
    return 0;
}