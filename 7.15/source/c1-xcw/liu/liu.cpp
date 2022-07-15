#include <bits/stdc++.h>
using namespace std;
vector<int>f[400010][2];
int n,m,a,b,q,cnt=1,x[400020],fa[400020],ans[400020];
bool vis[400010],v[400020],vis1[400010];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void k(int i){
	vis[i]=1;
	for(int j=0;j<f[i][0].size();j++){
		if(vis[f[i][0][j]])continue;
//		cout<<f[i][0][j]<<" ";
		vis[f[i][0][j]]=1;
		k(f[i][0][j]);
	}
	return;
}
void k1(int i){
	vis1[i]=1;
	for(int j=0;j<f[i][0].size();j++){
		if(vis1[f[i][0][j]])continue;
		int fx=find(i),fy=find(f[i][0][j]);
		fa[fx]=fy;
//		cout<<f[i][0][j]<<" ";
		vis1[f[i][0][j]]=1;
		k(f[i][0][j]);
	}
	return;
}
int main(){
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		f[a][0].push_back(b);
		f[b][0].push_back(a);
		f[a][1].push_back(b);
		f[b][1].push_back(a);
	}
	scanf("%d",&q);
	k(0);
	for(int i=0;i<=n-1;i++){
		if(vis[i]==0)cnt++,k(i);
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&x[i]);
		v[x[i]]=1;
		for(int j=f[x[i]][0].size()-1;j>0;j--){
			f[x[i]][0].pop_back();
		}
	}
//	cout<<cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!v[i]&&vis1[i]==0){
			cnt++;
			k1(i);
		}
	}
	ans[q]=cnt;
	
//	cout<<find(5)<<" "<<find(0);
	for(int i=q-1;i>=1;i--){
		int flag=1,p=0;
		v[x[i]]=0;
		for(int j=0;j<f[x[i]][1].size();j++){
			f[x[i]][0][j]=f[x[i]][1][j];
			if(!v[f[x[i]][0][j]]){
				flag=0;
				if(find(x[i])!=find(f[x[i]][0][j])){
					fa[find(x[i])]=find(f[x[i]][0][j]);
					if(j==0){
						p=0;
					}
					else p--;
				}
			}
		}
		
		cnt=p+cnt+flag;
		ans[i]=cnt;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
/*
8 13
0 1
1 6
6 5
5 0
0 6
1 2
2 3
3 4
4 5
7 1
7 2
7 6
3 6
5
1
6
3
5
7
*/
