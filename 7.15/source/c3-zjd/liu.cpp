#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y;
struct code{
    int X,Y;
}asd[1000001];
bool q[1000001];
bool p[1000001];
int f[1000001];
int number;
int ans;
int F(int GF){
    if(f[GF]==GF)return GF;
    return f[GF]=F(f[GF]);
}
int main(){
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        asd[i].Y=y;f[F(x)]=F(y);
        asd[i].X=x;
    }
    for(int i=0;i<=n-1;i++){
        if(q[F(i)]==0){
            ans++;
            q[F(i)]=1;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<=n-1;i++){
       q[i]=0;f[i]=i;
    }
    ans=0;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&number);
        for(int y=1;y<=m;y++)
            if(asd[y].X!=number&&asd[y].Y!=number)
                f[F(asd[y].X)]=F(asd[y].Y);
            else{
                asd[y].X=0;
                asd[y].Y=0;
            }  
        p[number]=1;
        for(int i=0;i<=n-1;i++){
            if(p[i]==1)continue;
            if(q[F(i)]==0){
                q[F(i)]=1;
                ans++;
            }  
        }
        printf("%d\n",ans);
        for(int i=0;i<=n-1;i++)q[i]=0,f[i]=i;
        ans=0;
    }
    return 0;
}