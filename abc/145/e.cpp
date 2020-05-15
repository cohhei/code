#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int, int>;

int dp[3001][3001];
int main() {
  int N, T;
  cin >> N >> T;
  vector<P> ab(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    ab[i] = P(a, b);
  }
  sort(ab.begin(), ab.end());

  int ans = 0;
  rep(i, N) {
    int a = ab[i].first, b = ab[i].second;
    rep(j, T) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + a < T) dp[i + 1][j + a] = max(dp[i][j]+b, dp[i][j + a]);
    }
    int now = dp[i][T - 1] + b;
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}