#include<bits/stdc++.h>
// #define debug
// #define debugdp
using namespace std;
const int maxn=4e3+5;
const int maxq=2e4+5;
int n,p,Q;
struct node{
    int cost,happiness,time,id;
}a[maxn];
struct question{
    int day,money,id,ans;
}qu[maxq];
bool cmp_node(node x,node y){
    return (x.time==y.time)?x.id<y.id:x.time<y.time;
}
bool cmp_question(question x,question y){
    return (x.day==y.day)?x.money>y.money:x.day<y.day;
}
bool cmp_back(question x,question y){
    return x.id<y.id;
}
queue<node> q;
int dp[maxn];
int main(){//O(n^2q)
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    cin>>n>>p;
    for (int i=1;i<=n;i++){
        cin>>a[i].cost>>a[i].happiness>>a[i].time;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp_node);
    cin>>Q;
    for(int i=1;i<=Q;i++){
        cin>>qu[i].day>>qu[i].money;
        qu[i].id=i;
    }
    sort(qu+1,qu+1+Q,cmp_question);
    int begin=1,end=0;
    for(int i=1;i<=Q;i++){
        if(qu[i].day==qu[i-1].day){
            qu[i].ans=dp[qu[i].money];
            continue;
        }
        memset(dp,0,sizeof(dp));
        #ifdef debug
        printf("now q is %d\n",qu[i].id);
        #endif
        while(end<n&&a[end+1].time<=qu[i].day){//新的
            end++;
            #ifdef debug
            printf("/*----push %d\n",a[end].id);
            #endif
        }
        while(begin<=end&&a[begin].time+p<=qu[i].day){//过了
            #ifdef debug
            printf("/*----pop %d\n",a[begin].id);
            #endif
            begin++;
        }
        for(int j=begin;j<=end;j++){
            for(int k=qu[i].money;k>=a[j].cost;k--){
                dp[k]=max(dp[k],dp[k-a[j].cost]+a[j].happiness);
            }
        }
        #ifdef debugdp
        for(int j=1;j<=qu[i].money;j++){
            printf("dp[%d]=%d\n",j,dp[j]);
        }
        #endif
        qu[i].ans=dp[qu[i].money];
    }
    sort(qu+1,qu+1+Q,cmp_back);
    for(int i=1;i<=Q;i++){
        cout<<qu[i].ans<<endl;
    }
    return 0;
}