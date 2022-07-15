#include<bits/stdc++.h>
// #define debug
using namespace std;
const int maxn = 4e5 + 5;
int n , m , k;
vector<int> nbr[maxn];
int cut[maxn];
int root , tim , this_tim;
int dfn[maxn] , low[maxn];
bool del[maxn];
void tarjan(int x){
	dfn[x]=low[x]=++tim;
	int cnt=0;
	for(int i=0;i<nbr[x].size();i++){
		int y=nbr[x][i];
        if(del[y]){
            continue;
        }
        if(dfn[y]<=this_tim){
            tarjan(y);
            low[x]=min(low[x],low[y]);
            if(low[y]>=dfn[x]){
                cnt++;
                if(x!=root||cnt>=2){
                    cut[x]=1;
                }
            }
        }
        else{
            low[x]=min(low[x],dfn[y]); 
        }
	}
}
int main(){//O(kn+km)
    freopen("liu.in","r",stdin);
    freopen("liu.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i ++){
        int x,y;
        cin>>x>>y;
        x++;
        y++;
        nbr[x].push_back(y);
        nbr[y].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            ans++;
            root=i;
            tarjan(root);
        }
    }
    #ifdef debug
    printf("/*-----------------------*/\n");
    for(int i=1;i<=n;i++){
        if(cut[i]){
            printf("dot no.%d is an cut-dot\n",i);
        }
    }
    printf("/*-----------------------*/\n");
    #endif
    cout<<ans<<endl;
    cin >> k;
    for(int i =1;i<=k;i++){
        int x;
        cin>>x;
        x++;
        del[x]=1;
        if(cut[x]){
            cout<<++ans<<endl;
        }
        else{
            this_tim+=n;
            for(int i=1;i<=n;i++){
                if(dfn[i]<=this_tim){
                    root=i;
                    tarjan(root);
                }
            }
            #ifdef debug
            printf("/*-----------------------*/\n");
            for(int i=1;i<=n;i++){
                if(cut[i]){
                    printf("dot no.%d is an cut-dot\n",i);
                }
            }
            printf("/*-----------------------*/\n");
            #endif
            cout<<ans<<endl;
        }
    }
    return 0;
}