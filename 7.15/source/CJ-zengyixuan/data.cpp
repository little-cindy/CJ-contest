#include<bits/stdc++.h>
#define random(ret) (rand()%ret)
using namespace std;
int main()
{
    freopen("god.in","w",stdout); 
    int n=100,p=1000;
    srand(time(NULL));
    cout<<n<<" "<<p<<endl;
    for(int i=1;i<=n;++i) 
    {
        cout<<random(1000)+1<<" "<<random(1000)+1<<" "<<1<<endl; 
    }
    int q=1000;
    cout<<q<<endl; 
    for(int i=1;i<=q;++i)
    {
        cout<<1<<" "<<4000<<endl;
    }
    return 0; 
}