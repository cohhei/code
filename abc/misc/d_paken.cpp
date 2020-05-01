#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[999][4];
char color[] = {'R', 'B', 'W'};

int main() {
  int n;
  cin >> n;

  vector<string> s(5);
  rep(i, 5) cin >> s[i];

  auto cost = [&](int i, char c) {
    int cnt = 0;
    rep(r, 5) if (s[r][i] != c) cnt++;
    return cnt;
  };

  for (int i = 0; i <= n; i++) rep(j, 3) dp[i][j] = 1001001001;
  rep(j, 3) {
    int cost_j = cost(0, color[j]);
    dp[0][j] = cost_j;
  }

  rep(i, n - 1) rep(j, 3) {
    rep(k, 3) {
      if (j == k) continue;
      int cost_k = cost(i + 1, color[k]);
      dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cost_k);
    }
  }

  int ans = dp[n - 1][0];
  rep(j, 3) ans = min(ans, dp[n - 1][j]);
  cout << ans << endl;
  return 0;
}