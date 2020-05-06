#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9;
const int MAX_V = 301;

int V, E;

// dp[i][j]: iから（kを通って）jまでの最短距離
// kの次元は使い回せるので省略できる
int dp[MAX_V][MAX_V];

void wf() {
  rep(i, V) rep(j, V) rep(k, V) {
    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
  }
}

int main() {
  cin >> V >> E;
  rep(i, V) rep(j, V) if (i != j) dp[i][j] = INF;
  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    s--;
    t--;
    dp[s][t] = d;
    dp[t][s] = d;
  }
  wf();
  int ans = INF;
  rep(i, V) {
    int mx = 0;
    rep(j, V) {
      mx = max(mx, dp[i][j]);
    }
    ans = min(ans, mx);
  }
  cout << ans << endl;
  return 0;
}