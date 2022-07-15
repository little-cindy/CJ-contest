#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
int usern;

int x,y;
int userx,usery;

int infn;
int a[N];
map<int,int> mp;
map<int,int> hang[N],lie[N];
map<int,int> tot_use;

int main(int argc, char **argv) {
	registerLemonChecker(argc, argv);
	usern=ouf.readInt();
	n=ans.readInt();
//	ans.readEoln();
//	ouf.readEoln();
	if(usern!=n){
		quitf(_wa, "the size of the matrix is wrong");
		return 0;
	}
	x=ans.readInt();
	y=ans.readInt();
	userx=ouf.readInt();
	usery=ouf.readInt();
	if(userx*usery!=n){
		quitf(_wa, "the size of the matrix is wrong");
		return 0;
	}
	infn=inf.readInt();
	//inf.readEoln();
	for(int i=1;i<=infn;i++){
		a[i]=inf.readInt();
		mp[a[i]]++;
	}
//	ouf.readEoln();
	for(int i=1;i<=userx;i++){
		for(int j=1;j<=usery;j++){
			int cur;
			cur=ouf.readInt();
			if(hang[i][cur]||lie[j][cur]){
				quitf(_wa, "there are same numbers in one of the r or c");
				return 0;
			}
			hang[i][cur]=lie[j][cur]=1;
			tot_use[cur]++;
		}
//		ouf.readEoln();
	}
	for(int i=1;i<=n;i++){
		if(tot_use[a[i]]>mp[a[i]]){
			quitf(_wa, "there are same numbers are used too much times");
			return 0;
		}
	}
	quitf(_ok, "AC");
	return 0;
}
