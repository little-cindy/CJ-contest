#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,K,fa[N],sta[N],top,cnt,ans[N];
vector<int>e[N];
bool wbt[N];
int get(int x){
	return x==fa[x]?x:(fa[x]=get(fa[x]));
}
inline void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m);cnt=n;
	for(int i=1;i<=n;i++){
		fa[i]=i;wbt[i]=0;
	}
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		x++;y++;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	scanf("%d",&K);
	for(int i=1,j;i<=K;i++){
		scanf("%d",&j);j++;
		sta[++top]=j;wbt[j]=1;
	}
	for(int i=1;i<=n;i++){
		if(wbt[i])continue;
		for(int v:e[i])if((!wbt[v])&&get(i)!=get(v)){
			merge(i,v);cnt--;
		}
	}
	while(top){
		ans[top]=cnt-top;wbt[sta[top]]=0;
		for(int v:e[sta[top]])if((!wbt[v])&&get(v)!=get(sta[top])){
			merge(v,sta[top]);cnt--;
		}
		top--;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=K;i++)printf("%d\n",ans[i]);
	return 0;
}
