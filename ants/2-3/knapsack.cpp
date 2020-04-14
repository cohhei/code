#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
4 5
2 3
1 2
3 4
2 2
=> 7
*/
const int MAX_N = 100;
const int MAX_W = 10000;
int dp[MAX_N + 1][MAX_W + 1];
int main() {
  int n, W;
  cin >> n >> W;
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    rep(j, W + 1) {
      if (j < w)
        dp[i + 1][j] = dp[i][j];
      else
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v);
    }
  }
  cout << "=> " << dp[n][W] << endl;
  rep(i, n + 1) {
    rep(j, W + 1) printf("%d ", dp[i][j]);
    cout << endl;
  }
  return 0;
}