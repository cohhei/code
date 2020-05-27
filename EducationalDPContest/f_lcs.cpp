#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
int dp[3001][3001];
int main() {
  string s, t;
  cin >> s >> t;
  int ls = s.size(), lt = t.size(), l = max(ls, lt);

  string ans = "                                   ";
  rep(i, ls) {
    rep(j, lt) {
      if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  int i = ls, j = lt;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j])
      --i;
    else if (dp[i][j] == dp[i][j - 1])
      --j;
    else {
      ans = s[i - 1] + ans;
      --i, --j;
    }
  }
  cout << ans << endl;
  return 0;
}