#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll dp[101][4][4];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> plan(n, -1);
  rep(i, K) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    plan[a] = b;
  }

  int mod = 10000;
  dp[0][3][3] = 1;
  rep(i, n) rep(j, 4) rep(k, 4) rep(l, 3) {
    int p = plan[i];
    if (p >= 0 && p != l) continue;
    if (j == k && k == l) continue;
    dp[i + 1][k][l] += dp[i][j][k] % mod;
  }
  ll ans = 0;
  rep(j, 4) rep(k, 4) ans += dp[n][j][k];
  ans %= mod;
  cout << ans << endl;

  return 0;
}