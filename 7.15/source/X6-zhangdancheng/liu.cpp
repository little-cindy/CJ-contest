#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,fa[N],k,id[N],cnt,u,v,ans[N];
vector<int> nbr[N];
bool flag[N];
int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
template<typename T>
inline void read(T &s){
	s=0;bool flag=true;char ch=getchar();
	while(ch!='-' && !isdigit(ch)) ch=getchar();
	if(ch=='-') flag=false,ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	s=(flag?s:-s);return;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		read(u),read(v);u++,v++;
		nbr[u].push_back(v),nbr[v].push_back(u);
	}
	read(k);cnt=n-k;
	for(int i=1;i<=k;i++) read(id[i]),flag[++id[i]]=true;
	for(int i=1;i<=n;i++)
		for(int j=0;j<nbr[i].size();j++){
			int son=nbr[i][j];
			if(flag[son] || flag[i]) continue;
			if(find(i)==find(son)) continue;
			fa[find(i)]=find(son);cnt--;
		}
	ans[k+1]=cnt;
	for(int i=k;i>=1;i--){
		flag[id[i]]=false,cnt++;
		for(int j=0;j<nbr[id[i]].size();j++){
			int son=nbr[id[i]][j];
			if(flag[son]) continue;
			if(find(id[i])==find(son)) continue;
			fa[find(id[i])]=find(son),cnt--;
		}
		ans[i]=cnt;
	}
	for(int i=1;i<=k+1;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
时光倒流，并查集维护 
*/
