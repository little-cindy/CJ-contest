#include <bits/stdc++.h>
using namespace std;

const int N = 27720;
int res1[N + 10], res2[N + 10];

int main() {
  freopen("ex_liu2.out", "r", stdin);
  for (int i = 1; i <= N; ++i) cin >> res1[i];
  freopen("liu.out", "r", stdin);
  for (int i = 1; i <= N; ++i) cin >> res2[i];
  int cnt = 0;
  for (int i = 1; i <= N; ++i)
    if (res1[i] ^ res2[i]) {
      cout << "FIND DIFFRENCE ON COLUMN " << i << endl;
      ++cnt;
    }
  if (!cnt)
  cout << "ACCEPTED" << endl;
}