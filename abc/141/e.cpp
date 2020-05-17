#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int> > dp(n + 1, vector<int>(n + 1));
  dp[n - 1][n - 1] = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (i == j) continue;
      if (s[i] != s[j]) continue;
      dp[i][j] = dp[i + 1][j + 1] + 1;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if (i >=j)continue;
      int now =min(dp[i][j], j-i);
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}