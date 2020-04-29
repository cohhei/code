#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int dp[101][10001];
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N);
  vector<int> w(N);
  rep(i, N) cin >> v[i] >> w[i];

  rep(i, N) rep(j, W + 1) {
    if (j < w[i])
      dp[i + 1][j] = dp[i][j];
    else
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
  }

  cout << dp[N][W] << endl;
  return 0;
}