#include<bits/stdc++.h>
const int N=105;
int c[N],h[N],t[N]; 
int dp[4005]; 
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
static inline int read()
{
    register int s=0; register char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return s; 
}
void write(register int ret)
{
    if(ret>9) write(ret/10);
    *O++='0'+ret%10;
}
int main()
{
    freopen("god.in","r",stdin);
    freopen("god.out","w",stdout); 
    register int n=read(),p=read();
    for(register int i=1;i<=n;++i)
    {
        c[i]=read();h[i]=read();t[i]=read();
    }
    register int q=read();
    for(register int i=1;i<=q;++i)
    {
        register int a=read(),b=read();
        // cout<<"Answering : a = "<<a<<" b = "<<b<<endl; 
        if(i>1) memset(dp,0,sizeof(dp));
        for(register int j=1;j<=n;++j)
        {   
            if(t[j]<=a&&t[j]+p>a) 
            {
                // cout<<" Update by : "<<j<<endl; 
                for(register int k=b;k>0;--k)
                {
                    // cout<<"  dp["<<k<<"] : "<<dp[k]<<"->";
                    if(k>=c[j]&&dp[k-c[j]]+h[j]>dp[k])dp[k]=dp[k-c[j]]+h[j]; 
                    // cout<<dp[k]<<endl; 
                }
            }
        } 
        write(dp[b]); *O++='\n'; 
    }
    fwrite(obuf,O-obuf,1,stdout);
    return 0;
}