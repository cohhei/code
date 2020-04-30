#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[1001][1001];
int main() {
  int q;
  cin >> q;
  rep(qq, q) {
    string x, y;
    cin >> x >> y;
    int len_x = x.size();
    int len_y = y.size();
    rep(i, len_x) rep(j, len_y) {
      if (x[i] == y[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
    cout << dp[len_x][len_y] << endl;
  }
  return 0;
}