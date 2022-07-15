#include<bits/stdc++.h>
using namespace std;
int n,p,q,mt,ll=1;
struct query{
    int a,b,pos;
}qq[20001];
struct thing{
    int c,h,t;
}l[4001];
int dp[4001],ans[40001],vis[40001];
int cmp(query o,query oo){
    return o.a<oo.a;
}
int cmpp(thing o,thing oo){
    return o.t<oo.t;
}
int main(){
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);  
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>l[i].c>>l[i].h>>l[i].t;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>qq[i].a>>qq[i].b;
        qq[i].pos=i;
    }
    sort(l+1,l+n+1,cmpp);
    sort(qq+1,qq+q+1,cmp);
    for(int i=1;i<=q;i++){
        int w[4001],m[4001],tt[4001],lw=0;
        for(int j=1;j<=n;j++){
            if(l[j].t<=qq[i].a&&l[j].t+p-1>=qq[i].a)
                w[++lw]=l[j].h,m[lw]=l[j].c,tt[lw]=l[j].t;
        }
        for(int j=1;j<=lw;j++){
            for(int k=qq[i].b;k>=m[j];k--){
                dp[k]=max(dp[k-m[j]]+w[j],dp[k]);
            }
        }
        ans[qq[i].pos]=dp[qq[i].b];
        memset(dp,0,sizeof(dp));
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}