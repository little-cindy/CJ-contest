#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define re register
using namespace std;
 
inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}
 
const int N=400000+10;
 
int n;
int a[N],S[N],cnt[N];
vector<pair<int,int> > vec;
vector<int> num;
vector<vector<int> > ans;
 
int main() {
	freopen("sky.in", "r", stdin);
	freopen("sky.out", "w", stdout);
	n=read();
    for (re int i=1;i<=n;++i) S[i]=a[i]=read();
    sort(S+1,S+n+1); int m=unique(S+1,S+n+1)-S-1;
    for (re int i=1;i<=n;++i) a[i]=lower_bound(S+1,S+m+1,a[i])-S;
    
    for (re int i=1;i<=n;++i) ++cnt[a[i]];
    for (re int i=1;i<=m;++i) vec.push_back(make_pair(cnt[i],i));
    sort(vec.begin(),vec.end());
    int ansS=0,ansr,ansc;
    for (re int r=1;r*r<=n;++r) { int s=0;
        for(int j = 0; j < vec.size(); j++) s+=min(vec[j].first,r);
        int c=s/r;
        if (c<r) continue;
        if (r*c>ansS) ansS=r*c,ansr=r,ansc=c;
    }
    printf("%d\n%d %d\n",ansS,ansr,ansc);
    
    reverse(vec.begin(),vec.end());
    for (int i = 0; i < vec.size(); i++) {
        for (re int j=1;j<=min(ansr,vec[i].first);++j)
            num.push_back(vec[i].second);
    }
    ans.resize(ansr);
    for (re int i=0;i<ansr;++i) ans[i].resize(ansc);
    for (re int i=0,x=0,y=0;i<ansS;++i) {
        ans[x][y]=num[i]; ++x,++y;
        if (x==ansr) x=0,y-=ansr-1;
        if (y<0) y+=ansc;
        if (y>=ansc) y-=ansc;
    }
    for (re int i=0;i<ansr;++i) {
        for (re int j=0;j<ansc;++j) printf("%d ",S[ans[i][j]]);
        puts("");
    }
    return 0;
}
