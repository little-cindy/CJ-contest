#include<bits/stdc++.h>
#define gc getchar
using namespace std;
const int N=2e5+5;
int an[N<<1];
int read()
{
    int o=0,f=1;
    char ch=gc();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(ch<='9'&&ch>='0')
    {
        o=(o<<3)+(o<<1)+ch-'0';
        ch=gc();
    }
    return o*f;
}
int main()
{
    int n;
    n=read();
    freopen("liu.out","r",stdin);
    freopen("che.out","w",stdout);
    for(int i=1;i<=n;i++) an[i]=read();
    freopen("liu.ans","r",stdin);
    bool ac=1;
    for(int i=1;i<=n;i++)
    {
        int in=read();
        if(in!=an[i])
        {
            ac=0;
            cout<<i<<' '<<an[i]<<' '<<in<<endl;
        }
    }
    if(ac) cout<<"AC"<<endl;
    return 0;
}