#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll INF = 1e11;
const int MAX_V = 10;

// dp[i][j]: iから（kを通って）jまでの最短距離
// kの次元は使い回せるので省略できる
int dp[MAX_V][MAX_V];

void wf() {
  rep(i, 10) rep(j, 10) rep(k, 10) {
    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
  }
}

int main() {
  int H, W;
  cin >> H >> W;

  rep(i, 10) rep(j, 10) cin >> dp[i][j];
  wf();

  int ans = 0;
  rep(i, H) rep(j, W) {
    int a;
    cin >> a;
    if (a != -1) ans += dp[a][1];
  }
  cout << ans << endl;
  return 0;
}