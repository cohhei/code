#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[100001];
vector<int> to[100001];

int lp(int v) {
  if (dp[v] != -1) return dp[v];
  if (to[v].size() == 0) return 0;
  for (int u : to[v]) dp[v] = max(dp[v], lp(u) + 1);
  return dp[v];
}

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    to[x].push_back(y);
  }
  rep(i, n) dp[i] = -1;
  int ans = 0;
  rep(i, n) ans = max(ans, lp(i));
  cout << ans << endl;
  return 0;
}