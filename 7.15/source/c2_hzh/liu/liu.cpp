#include<bits/stdc++.h>
using namespace std;
int n,m,ans,anss;
int num_edge,nf;
int head[4001],f[4001],r[4001],vis[4001],ee[4001][4001],ss[4001];
int vvis[4001][4001];
void dfs(int tmp){
    vis[tmp]=1;
    for(int j=0;j<n;j++){
        if(vis[j]==0&&ee[tmp][j]==1)
            dfs(j);
    }
}
struct Edge{
    int net,to;
}edge[4001];
void add_edge(int from,int to){
    edge[++num_edge].net=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
int main(){
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u!=v&&vvis[u][v]==0){
            vvis[u][v]=1;
            vvis[v][u]=1;
            add_edge(u,v);
            add_edge(v,u);
            r[u]++,r[v]++;
            ee[u][v]=1,ee[v][u]=1;
        }
    }
    cin>>nf;
    for(int i=1;i<=nf;i++){
        cin>>f[i];
        ss[f[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=nf;i++){
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int j=head[f[i]];j;j=edge[j].net){
            ee[f[i]][edge[j].to]=0;
            ee[edge[j].to][f[i]]=0;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0&&ss[i]==0){
               dfs(i);
               ans++;
          }
        }
        cout<<ans<<endl;
    }
    return 0;
}




/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7



7 6
0 1
0 1
1 2
1 2
3 4
5 6
1
5
*/