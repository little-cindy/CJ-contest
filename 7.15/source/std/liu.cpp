#include<iostream>
#include<cstdio>
#define f(i,a,b) for(register int i=a;i<=b;i++)
#define fd(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
int k,n,m,head[400002],tot,broken[400002],ans[400003];
int father[400003];
struct Node
{
    int next,node,from;
}h[400002];
inline void Add_Node(int u,int v)
{
    h[++tot].from=u;
    h[tot].next=head[u];
    head[u]=tot;
    h[tot].node=v;
}
bool Broken[400001];
inline int Get_father(int x)
{
    if(father[x]==x)    return x;
    return father[x]=Get_father(father[x]);
}
inline void hb(int u,int v)
{
    u=Get_father(u),v=Get_father(v);
    if(u!=v)    father[v]=u;
}
int main()
{
	freopen("liu.in", "r", stdin);
	freopen("liu.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    f(i,0,n)
        father[i]=i,head[i]=-1;
    f(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        Add_Node(x,y);
        Add_Node(y,x); 
    }
    cin>>k;
    f(i,1,k)
    {
        cin>>broken[i];
        Broken[broken[i]]=1;
    }
    int total=n-k;
    f(i,1,2*m)
        if(!Broken[h[i].from] && !Broken[h[i].node] && Get_father(h[i].from)!=Get_father(h[i].node))
		{
            total--;
            hb(h[i].from,h[i].node);
        }
    ans[k+1]=total;
    fd(i,k,1)
    {
        total++;
        Broken[broken[i]]=0;
        for(int j=head[broken[i]];j!=-1;j=h[j].next)
        {
            if(!Broken[h[j].node] && Get_father(broken[i])!=Get_father(h[j].node))
            {
                total--; 
                hb(broken[i],h[j].node);
            }
        }
        ans[i]=total;
    }
    f(i,1,k+1)    cout<<ans[i]<<endl;
    return 0;
}
