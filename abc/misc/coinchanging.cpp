// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int dp[50001];
int main() {
  memset(dp, 1, sizeof(dp));
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  rep(i, m) cin >> c[i];

  dp[0] = 0;
  rep(i, m) rep(j, n + 1) {
    if (j + c[i] > n)
      break;
    else
      dp[j + c[i]] = min(dp[j] + 1, dp[j + c[i]]);
  }

  cout << dp[n] << endl;
  return 0;
}