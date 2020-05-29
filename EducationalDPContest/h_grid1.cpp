#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;
ll dp[1001][1001];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  dp[0][0] = 1;
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') continue;
      if (i > 0 && a[i - 1][j] == '.') dp[i][j] += dp[i - 1][j];
      if (j > 0 && a[i][j - 1] == '.') dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}