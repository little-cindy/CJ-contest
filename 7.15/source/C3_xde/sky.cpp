#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
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
int n,a[N],mp[N],mt,ct[N];
int p,q,maxp,maxq,rt[N],sf[N];
vector<int>vp,rp;
int main(){
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    read(n);int i,j,k;
    for(i=1;i<=n;++i)read(a[i]),mp[i]=a[i];
    sort(mp+1,mp+n+1),mt=unique(mp+1,mp+n+1)-mp;
    for(i=1;i<=n;++i)++ct[lower_bound(mp+1,mp+mt,a[i])-mp];
    for(i=1;i<mt;++i)rt[i]=ct[i];
    sort(rt+1,rt+mt);
    for(i=1;i<mt;++i)sf[i]=sf[i-1]+rt[i];
    for(p=1;p<=640;++p){
        q=lower_bound(rt+1,rt+mt,p)-rt-1;
        q=sf[q]+(mt-q-1)*p,q=q/p;if(q<p)continue;
        if(p*q>maxp*maxq)maxp=p,maxq=q;
    }p=maxp,q=maxq;
    printf("%d\n%d %d\n",p*q,q,p);
    for(i=1;i<mt;++i)rt[i]=i;
    sort(rt+1,rt+mt,[&](int x,int y){return ct[x]>ct[y];});
    for(i=1;i<mt;++i)
        for(j=1,k=min(ct[rt[i]],p);j<=k;++j)
            vp.push_back(mp[rt[i]]);
    // rp.resize(p*q);
    for(i=0;i<p*q;++i){
        k=(p*q+i-(i%p)*p)%(p*q);
        printf("%d ",vp[k]);
        if((i+1)%p==0)putchar('\n');
    }
    return 0;
}