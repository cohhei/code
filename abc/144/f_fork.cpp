#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  vector<vector<int>> ot(n);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    to[s].push_back(t);
    ot[t].push_back(s);
  }

  vector<double> dp(n);
  dp[n - 1] = 0;
  for (int v = n - 2; v >= 0; --v) {
    int deg = to[v].size();
    for (int u : to[v]) dp[v] += (dp[u] + 1) / deg;
  }

  vector<double> p1(n);
  p1[0] = 1;
  for (int v = 1; v < n; ++v) {
    for (int u : ot[v]) {
      p1[v] += p1[u] / to[u].size();
    }
  }

  double ans = dp[0];
  for (int v = 0; v <= n - 2; ++v) {
    int deg = to[v].size();
    if (deg == 1) continue;
    double x = dp[v] * deg / (deg - 1);
    for (int u : to[v]) {
      double nx = x - (dp[u] + 1) / (deg - 1);
      ans = min(ans, dp[0] + p1[v] * (nx - dp[v]));
    }
  }

  printf("%.10f\n", ans);
  return 0;
}
