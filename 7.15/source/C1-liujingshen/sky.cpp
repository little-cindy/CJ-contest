#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<pair<int,int> >q;
vector<int>v,ans[655];
map<int,int>mp;
int lne(int x){
	for(int i=sqrt(x);i>=1;i--)
		if(!(x%i))
			return i;
}
void output(int len,int wid){
	int lastl=1,k=1,l=1;
	for(int i=1;i<=wid;i++)
		for(int j=0;j<=len;j++)
			ans[i].push_back(0);
	cout<<wid<<' '<<len<<endl;
	while(!q.empty()){
		pair<int,int> x=q.top();
		q.pop();
		while(x.first--){
			ans[k][l]=x.second;
			if(k==wid)
				k=1,lastl++,l=lastl;
			else
				k++,l=l%len+1;
		}
	}
	for(int i=1;i<=wid;i++){
		for(int j=1;j<=len;j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
}
int main(){
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		mp[a]++;
		if(mp[a]==1)
			v.push_back(a);
	}
	for(int i=0;i<v.size();i++)
		q.push(make_pair(mp[v[i]],v[i]));
	if(q.size()==1){
		cout<<1<<endl<<1<<' '<<1<<endl<<q.top().second<<endl;
		return 0;
	}	
	for(int i=n;i>=1;i--){
		int k=lne(i);
		pair<int,int> x=q.top();
		if(x.first<=k){
			cout<<i<<endl;
			output(i/k,k);
			return 0;
		}
		q.pop();
		x.first--;
		q.push(x);
	}
	return 0;
}
