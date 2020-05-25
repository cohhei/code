#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_W = 1e9 + 1;
ll dp[101][MAX_W];

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n), w(n);
  rep(i, n) cin >> w[i] >> v[i];

  rep(i, n) rep(j, W + 1) {
    if (j < w[i])
      dp[i + 1][j] = dp[i][j];
    else
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
  }
  cout << dp[n][W] << endl;
  return 0;
}