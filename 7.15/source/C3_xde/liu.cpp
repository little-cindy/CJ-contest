#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
int f[N],ht[N],n,m,k,ans[N];
vector<int>lk[N];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
int main(){
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    read(n,m);int i,x,y;
    for(i=1;i<=m;++i){
        read(x,y),++x,++y;
        lk[x].push_back(y);
        lk[y].push_back(x);
    }
    for(i=1;i<=n;++i)f[i]=i;
    read(k),ans[0]=n-k;
    for(i=k;i;--i)read(ht[i]),f[++ht[i]]=0;
    for(x=1;x<=n;++x)
        if(f[x])for(int z:lk[x])
            if(f[z]&&gf(x)!=gf(z))
                --ans[0],f[f[x]]=f[z];
    for(i=1;i<=k;++i){
        ans[i]=ans[i-1]+1,x=ht[i],f[x]=x;
        for(int z:lk[x])
            if(f[z]&&gf(x)!=gf(z))
                --ans[i],f[f[x]]=f[z];
    }
    for(i=k;~i;--i)printf("%d\n",ans[i]);
    return 0;
}