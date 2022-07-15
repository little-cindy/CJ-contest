#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N=4010,M=4010;

struct Node
{
	int c;
	int h;
	int l;
	int r;
}S[N];

int n,p;
int f[M];

int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&S[i].c,&S[i].h,&S[i].l);
		S[i].r=S[i].l+p-1;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
		{
			if(!(S[i].l<=a&&a<=S[i].r))continue;
			for(int j=b;j>=S[i].c;j--)
			{
				f[j]=max(f[j],f[j-S[i].c]+S[i].h);
			}
		}
		printf("%d\n",f[b]);
	}
	return 0;
}
