#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

long long dp[101][21];
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  dp[0][a[0]] = 1;
  for (int i = 0; i < n - 2; i++) {
    rep(j, 21) {
      if (j + a[i] <= 20) dp[i + 1][j + a[i]] += dp[i][j];
      if (j - a[i] >= 0) dp[i + 1][j - a[i]] += dp[i][j];
    }
  }
  
  cout << dp[n - 2][a[n - 1]] << endl;
  // rep(i, n) {
  //   rep(j, 20) printf("%3ld", dp[i][j]);
  //   cout << endl;
  //   if (i == n - 2) {
  //     rep(j, a[n - 1]) cout << "   ";
  //     cout << "^" << endl;
  //   }
  // }
  return 0;
}