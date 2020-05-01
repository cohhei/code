#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll dp[201][202];
int main() {
  int d, n;
  cin >> d >> n;
  vector<int> t(d);
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  rep(i, d) cin >> t[i];
  rep(j, n) { cin >> a[j] >> b[j] >> c[j]; }

  auto suit = [&](int i, int j) { return a[j] <= t[i] && t[i] <= b[j]; };

  rep(i, d) rep(j, n) {
    if (!suit(i, j)) continue;
    rep(k, n) {
      if (!suit(i + 1, k)) continue;
      dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + abs(c[j] - c[k]));
    }
  }
  ll ans = 0;
  rep(j, n) ans = max(ans, dp[d - 1][j]);

  cout << ans << endl;
  return 0;
}