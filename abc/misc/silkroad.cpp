#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1000;
const int MAX_M = 1000;
int dp[MAX_M + 1][MAX_N + 1];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  vector<int> c(m);
  rep(i, m) cin >> c[i];

  // dp[city][day] = cost
  for (int i = 1; i <= n; i++) rep(j, m + 1) dp[i][j] = 1001001001;
  rep(i, n) rep(j, m) {
    dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j] + d[i] * c[j]);
  }

  cout << dp[n][m] << endl;
  return 0;
}
