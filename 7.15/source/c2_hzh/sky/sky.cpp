#include<bits/stdc++.h>
using namespace std;
int n,a[400001];
int main(){
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<n<<endl;
    cout<<'1'<<' '<<n<<endl; 
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}