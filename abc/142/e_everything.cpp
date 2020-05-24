#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
int main() {
  int n, m;
  cin >> n >> m;
  vector<P> key;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    int s = 0;
    rep(j, b) {
      int c;
      cin >> c;
      c--;
      s |= 1 << c;
    }
    key.push_back(P(s, a));
  }
  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  rep(s, 1 << n) {
    rep(i, m) {
      int t = s | key[i].first;
      int cost = dp[s] + key[i].second;
      dp[t] = min(dp[t], cost);
    }
  }
  int ans = dp.back();
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}