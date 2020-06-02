#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  // 桁dp
  int n = s.size();
  vector<vector<ll> > dp(
      n + 1, vector<ll>(13, 0));  // dp[k]: 13で割ったあまりがKのパターン数

  int mod = 1000000007;
  dp[0][0] = 1;
  const int N = 13;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    vector<ll> next(13);
    if (c == '?') {
      rep(k, 10) rep(j, 13) {
        dp[i + 1][((j * 10) + k) % 13] += dp[i][j];
        dp[i + 1][((j * 10) + k) % 13] %= mod;
      }
    } else {
      int k = c - '0';
      rep(j, 13) {
        dp[i + 1][((j * 10) + k) % 13] += dp[i][j];
        dp[i + 1][((j * 10) + k) % 13] %= mod;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}