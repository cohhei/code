#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 2e9;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<int> dp(n, INF);
  dp[0] = 0;
  rep(i, n) {
    for (int j = 1; j <= k; j++)
      dp[i + j] = min(dp[i + j], abs(h[i + j] - h[i]) + dp[i]);
  }
  cout << dp[n - 1] << endl;
  return 0;
}