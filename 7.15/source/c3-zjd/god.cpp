#include<bits/stdc++.h>
using namespace std;
int n,p,q;
struct code{
    int c,h,t;
}a[1000000];
int f[100000];
int main(){
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i].c>>a[i].h>>a[i].t;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int A,B;
        cin>>A>>B;
        for(int u=1;u<=n;u++){
            if(a[u].t>A||a[u].t+p-1<A)continue;
            for(int o=B-a[u].c+1;o>=0;o--){
                f[o+a[u].c]=max(f[o+a[u].c],f[o]+a[u].h);
            }
        }
        cout<<f[B]<<endl;
        for(int i=0;i<=B+10;i++)f[i]=0;
    }
    return 0;
}