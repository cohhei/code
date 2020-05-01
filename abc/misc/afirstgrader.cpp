#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

long long dp[101][21];
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n - 1) rep(j, 20) {
    // if (i == 0) {
    if (j == a[i]) {
      dp[i][j] = 1;
      // else
      //   dp[i][j] = 0;
    } else {
      dp[i + 1][j + a[i]] = dp[i][j - a[i + 1]] + dp[i][j + a[i + 1]];
    }
  }
  cout << dp[n - 2][a[n - 1] - 1] << endl;
  rep(i, n) {
    rep(j, 20) printf("%3d", dp[i][j]);
    cout << endl;
    if (i == n - 2) {
      rep(j, a[n - 1]) cout << "   ";
      cout << "^" << endl;
    }
  }
  return 0;
}