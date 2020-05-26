#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;

const ll INF = 2e18;
const int MAX_V = 100001;
ll dp[MAX_V];

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n), w(n);
  rep(i, n) cin >> w[i] >> v[i];

  rep(j, MAX_V + 1) dp[j] = INF;
  dp[0] = 0;
  rep(i, n + 1) for (int j = MAX_V; j >= 0; j--) {
    if (j - v[i] >= 0) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
  }
  ll ans = 0;
  rep(j, MAX_V) if (dp[j] <= W) ans = max(ans, (ll)j);
  cout << ans << endl;
  return 0;
}