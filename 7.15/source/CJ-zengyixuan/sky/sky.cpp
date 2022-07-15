#include<bits/stdc++.h>
using namespace std;
vector<int>lsh,num;
const int N=5e5+10;
int a[N];long long sum[N]; 
vector<int>correct[N]; 
int t=-1,n_;
pair<int,int> nextxy(int x,int y)
{
    // cout<<"for x = "<<x<<" y = "<<y<<" nextx/y : "; 
    if(x<t-1) 
        return /*cout<<(x+1)%t<<" "<<(y+1)%n_<<endl*/make_pair((x+1)%t,(y+1)%n_);
    else return /*cout<<"1"<<" "<<(y-x+2+n_)%n_<<endl,*/make_pair(0,(y-x+1+n_)%n_);
}
int main()
{
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout); 
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]),lsh.push_back(a[i]);
    sort(lsh.begin(),lsh.end()); 
    int cnt=unique(lsh.begin(),lsh.end())-lsh.begin();
    sort(a+1,a+n+1);int c=0,maxn=0; 
    for(int i=1;i<=n;++i)
    {
        ++c;
        if(a[i]!=a[i+1]) maxn=max(maxn,c),num.push_back(c),c=0; 
    }
    sort(num.begin(),num.end()); 
    // cout<<"a : "; 
    // for(int i=1;i<=n;++i)cout<<a[i]<<" "; 
    // puts(""); 
    // cout<<"num : "; 
    // for(int i=0,len=num.size();i<len;++i)cout<<num[i]<<" "; 
    // puts(""); 
    for(int j=num.size()-1;j>=0;--j) sum[j+1]=sum[j+2]+num[j];  
    // cout<<"sum : "; 
    // for(int i=0,len=num.size();i<=len;++i)cout<<sum[i]<<" "; 
    // puts(""); 
    int ans=0;
    for(int i=sqrt(n);i>0;--i)
    {
        //qiu chu shi ji shang zui duo duo shao ge shu 
        int col=upper_bound(num.begin(),num.end(),i)-num.begin(); 
        // cout<<"for i = "<<i<<" col = "<<col<<endl; 
        //cha = n-sum[col] - (col~num.end())*i
        int rx=n-(sum[col+1]-i*(num.size()-col)); 
        // cout<<"after cutting down : rx : "<<rx<<endl; 
        if(rx<=ans) break; 
        int maxn=(int)(rx/i)*i; 
        // cout<<"maxn : "<<maxn<<endl; 
        if(rx/i<i) continue; 
        if(maxn>ans) ans=maxn,t=i;
    }
    //need test for n=1
    int col=upper_bound(num.begin(),num.end(),t)-num.begin(); 
    int rx=n-(sum[col+1]-t*(num.size()-col)); 
    maxn=(int)(rx/t)*t;
    n_=rx/t;c=0; 
    // cout<<"at last : t : "<<t<<" n_ : "<<n_<<endl; 
    for(int i=0;i<t;++i) 
    {
        correct[i].resize(n_+5); 
    } 
    int x=0,y=0; correct[0][0]=a[1]; c=1; int tot=1; 
    for(int i=2;i<=n;++i)
    {
        ++c; if(tot==ans) break; 
        pair<int,int>ti=nextxy(x,y); 
        // cout<<" to putin "<<a[i]<<" c : "<<c<<endl; 
        x=ti.first,y=ti.second; 
        correct[x][y]=a[i]; ++tot; if(tot==ans) break; 
        if(a[i+1]==a[i]&&c==t)
        {
            while(a[i+1]==a[i]) ++i;
            c=0; 
        }
        else if(a[i+1]!=a[i])c=0;
    }
    printf("%d\n",ans);
    printf("%d %d\n",t,n_); 
    for(int i=0,len=t;i<len;++i)
    {
        for(int j=0,len2=n_;j<len2;++j)
        {
            printf("%d ",correct[i][j]);
        }
        puts(""); 
    }
    return 0; 
}