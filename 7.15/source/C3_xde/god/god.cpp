#include<bits/stdc++.h>
using namespace std;
const int N=4e3+3,M=2e4+4,B=20001,C=4001;
namespace fast_rd{
    const int R=1e5+5;
    char buf[R+5],c;
    int it,ed,f;
    #define gc (it==ed&&(ed=(it=0)+fread(buf,1,R,stdin),it==ed)?EOF:buf[it++])
    template<typename _Tp>
    inline void read(_Tp &x){
        for(f=0,c=gc;c<48;c=gc)if(c=='-')f=!f;
        for(x=0;c>47;x=x*10+(48^c),c=gc);if(f)x=-x;
    }
    template<typename _Tp,typename..._tps>
    inline void read(_Tp &x,_tps&...y){
        read(x),read(y...);
    }
};
using fast_rd::read;
using pr=pair<int,int>;
int n,m,p,d[M<<2];
int f[22][N],ans[M];
vector<pr>nd[M],th[M<<2];
void build(int x=1,int l=1,int r=B,int dep=1){
    int md=l+r>>1,a=x<<1;d[x]=dep;
    if(l<r)build(a,l,md,dep+1),build(a|1,md+1,r,dep+1);
}
pr at;
void ins(int L,int R,int x=1,int l=1,int r=B){
    if(l>=L&&r<=R){th[x].push_back(at);return;}
    int md=l+r>>1,a=x<<1;
    if(L<=md)ins(L,R,a,l,md);
    if(md<R)ins(L,R,a|1,md+1,r);
}
void sol(int x=1,int l=1,int r=B){
    // cerr<<"start:"<<d[x]<<endl;
    memcpy(f[d[x]],f[d[x]-1],sizeof(f[d[x]]));
    for(auto p:th[x]){
        for(int i=C;i>=p.first;--i)
            f[d[x]][i]=max(f[d[x]][i],f[d[x]][i-p.first]+p.second);
    }
    if(l<r){
        int md=l+r>>1,a=x<<1;
        sol(a,l,md),sol(a|1,md+1,r);
    }else{
        for(int i=1;i<=C;++i)f[d[x]][i]=max(f[d[x]][i],f[d[x]][i-1]);
        // cerr<<"RT"<<endl;
        for(auto p:nd[l])ans[p.second]=f[d[x]][p.first];
    }
}
int main(){
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    read(n,p),build();
    int i,x,y,z;
    for(i=1;i<=n;++i){
        read(x,y,z);at=pr(x,y);
        ins(z,min(z+p-1,B));
    }read(m);
    for(i=1;i<=m;++i)
        read(x,y),nd[x].push_back(pr(y,i));
    for(i=1,sol();i<=m;++i)
        printf("%d\n",ans[i]);
    return 0;
}