#include<bits/stdc++.h>
using namespace std;
int n;
int a[400005];
int rd(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct edge{
	int k;
	int num;
}t[400005];
int tot=0;
bool cmp(edge x,edge y){
	return x.k>y.k;
}
bool check(int x,int nd){
	for(int i=1;i<=tot;i++){
	//	cout<<1<<" ";
		if(t[i].k-x>nd) return 0;
		if(t[i].k>x) nd=nd-t[i].k+x;
	}
	return 1;
}
int ans[1005][1005];
void find(int x,int y){
	int fy=1,fx=1;
	int now=fy;
	for(int i=1;i<=tot;i++){
		if(t[i].k>=x){
		//`	cout<<1<<"*"<<endl;
			for(int j=1;j<=x;j++) {
				ans[now][j]=t[i].num;
			//	cout<<q<<" "<<j<<endl;
				now++;if(now>y) now%=y;
			}
			fy++;
			now=fy;
		} 
		else{
			
		//	cout<<q<<" "<<h<<endl; 
			for(int j=1;j<=t[i].k;j++){
				printf("%d %d %d %d*\n",t[i].num,t[i].k,now,fx);
				ans[now][fx]=t[i].num;
				now++,fx++;
				if(fx>x) fx=1,fy++,now=fy;
				if(now>y) now%=y;
			}
		}
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++) printf("%d ",ans[j][i]);
		puts("");
	}
		
}
int main(){
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	n=rd();
	int k=0;
	for(int i=1;i<=n;i++) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		tot++;
		int cnt=1;
		while(i<n&&a[i+1]==a[i]){
			i++;
			cnt++;
		}
		t[tot].k=cnt;
		t[tot].num=a[i];
	}

	sort(t+1,t+tot+1,cmp);
	n++;
//	for(int i=1;i<=tot;i++){
//		printf("%d %d*\n",t[i].num,t[i].k);
//	}
	while(n--){
		k++;
		for(int i=sqrt(n);i>=1;i--){
		//	cout<<n<<" "<<i<<"*"<<" ";
			if(n%i!=0) continue;
		//	cout<<1;
			int n1=i,m1=n/i;
			if(!check(i,k)) continue;
		//	return 0;
			printf("%d\n",n);
			find(n1,m1);
			return 0;
		} 
	}
	
	return 0;
}


