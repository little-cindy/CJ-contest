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
int v[N],p[N],val[N],n;
long long ans;
int main(){
    freopen("smoke.in","r",stdin);
    freopen("smoke.out","w",stdout);
    read(n);int i,f,nv;
    for(i=1;i<=n;++i)read(v[i]);
    for(i=2;i<=n;++i)read(p[i]);
    for(i=1;i<=n;++i)
        for(f=i,nv=v[i];f;f=p[f],++nv)
            val[f]^=nv;
    for(i=1;i<=n;++i)ans+=val[i];
    printf("%lld\n",ans);
    return 0;
}