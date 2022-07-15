#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n;
int a[maxn];
map<int,int> t;
vector<int> val;
struct node{
    int val,num;
}b[maxn];
struct q_node{
    int val,num;
    bool operator < (const q_node tmp) const{
        return num<tmp.num;
    }
};
int tot;
bool cmp(node x,node y){
    return (x.num==y.num)?x.val<y.val:x.num>y.num;
}
bool check(int x){
    int sig=0;
    for(int i=1;i<=tot;i++){
        sig+=min(b[i].num,x);
    }
    int lie=sig/x;
    return lie>=x;
}
priority_queue<q_node> q;
vector<int> ans[maxn];
void print(int x){
    int sig=0;
    for(int i=1;i<=n;i++){
        sig+=min(b[i].num,x);
        q.push({b[i].val,min(b[i].num,x)});
    }
    int lie=sig/x;
    cout<<sig<<endl<<x<<' '<<lie<<endl;
    q_node cur=q.top();
    q.pop();
    for(int i=1;i<=lie;i++){
        for(int j=1;j<=x;j++){
            ans[j].push_back(cur.val);
            cur.num--;
            if(cur.num==0){
                cur=q.top();
                q.pop();
            }
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][(i+j-1)%lie]<<' ';
        }
        cout<<endl;
    }
    return;
}
int main(){//O(n log n)
    freopen("sky.in","r",stdin);
    freopen("sky.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(t[a[i]]==1){
            val.push_back(a[i]);
        }
    }
    tot=val.size();
    for(int i=0;i<tot;i++){
        b[i+1].val=val[i];
        b[i+1].num=t[val[i]];
    }
    sort(b+1,b+1+tot,cmp);
    int l=0,r=b[1].num+1;
    // cout<<"@";
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    // cout<<"@";
    print(l);
    return 0;
}