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
int n,m;
struct DSU{
    int fa[400005];
    void init(int n){for(int i=1;i<=n;i++) fa[i]=i;}
    // int find(int x){return (fa[x] != x)?find(x):x;}
    void merge(int x,int y){fa[x]=y;return;}
    
    bool remove(int x,int y){
        if(fa[y] == x){fa[y]=y; return 1;}
        else if(fa[x] == y){fa[x]=x; return 1;}
        return 0;
    }
}dsu;

struct Edge{
    int v,nxt;
}e[400005];
int head[400005],ecnt;
void add(int u,int v){
    ecnt++;
    e[ecnt].v=v;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
    return;
}


int safety[400005];
int des[400005];

bool vis1[400005];


void bfs1(int S,vector<int>&res){
    res.clear();
    queue<int> q; q.push(S);
    while(!q.empty()){
        int now=q.front(); q.pop();
        res.push_back(now);
        for(int i=head[now];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis1[v]){
                vis1[v]=1;
                q.push(v);
            }
        }
    }
    return;
}

bool vis2[400005];
bool vis3[400005];

struct Compare{
    bool operator()(int a,int b){return safety[a]<safety[b];}
};

void bfs2(int S){
    priority_queue<int,vector<int>,Compare> q; q.push(S);
    while(!q.empty()){
        int now=q.top(); q.pop();
        vis3[now]=1;
        int maxn=0;
        for(int i=head[now];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis3[v] && safety[v] > safety[maxn]) maxn=v;
            if(!vis2[v]){
                vis2[v]=1;
                q.push(v);
            }
        }
        if(maxn != 0) dsu.merge(now,maxn);
    }
    return;
}

//2.8K代码，一次过样例
//希望是个好兆头

//不用调试！一遍AC（至少过了大样例）！不愧是我！！

signed main(){
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    dsu.init(n=read());m=read();
    for(int i=1;i<=m;i++){
        int u=read()+1,v=read()+1;
        add(u,v); add(v,u);
    }
    memset(safety,127,sizeof(safety));safety[0]=0;
    int k=read();
    for(int i=1;i<=k;i++) safety[des[i]=read()+1]=i;
    int ans=0;
    vector<int> tmp;
    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            ans++;
            bfs1(i,tmp);
            int maxn=0;
            for(int j:tmp) if(safety[maxn] < safety[j]) maxn=j;
            bfs2(maxn);
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=k;i++){
        ans--;
        for(int j=head[des[i]];j;j=e[j].nxt){
            int v=e[j].v;
            ans+=dsu.remove(des[i],v);
        }
        printf("%d\n",ans);
    }
    // system("pause");
    return 0;
}
