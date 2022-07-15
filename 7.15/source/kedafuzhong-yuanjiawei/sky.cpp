#include <bits/stdc++.h>

using namespace std;

bool flag=false;

const int N=1010,M=1010;

int linenum;
int colnum;
bool vis[N];
int n;
bool line[N][M];
bool col[N][M];
int a[N];
int res[N][N];

bool check(int x,int y,int v)
{
	if(line[x][v]||col[y][v])return false;
	return true;
}

void dfs(int u)
{
	if(u==n+1)
	{
		printf("%d\n",linenum*colnum);
		printf("%d %d\n",linenum,colnum);
		for(int i=1;i<=linenum;i++)
		{
			for(int j=1;j<=colnum;j++)
			{
				printf("%d ",res[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int x=(u-1)/colnum+1,y=(u-1)%colnum+1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&check(x,y,a[i]))
		{
			res[x][y]=a[i];
			vis[i]=true;
			line[x][a[i]]=true;
			col[y][a[i]]=true;
			dfs(u+1);
			line[x][a[i]]=false;
			col[y][a[i]]=false;
			vis[i]=false;
		}
	}
}

int main()
{
	freopen("sky.in","r",stdin);
	freopen("sky.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(n)
	{
		for(int i=sqrt(n);i>=1;i--)//控制行数
		{
			if(n%i==0)
			{
				linenum=i;
				colnum=n/i;
				memset(line,0,sizeof line);
				memset(col,0,sizeof col);
				dfs(1);
			}
		}
		n--;
	}
}
