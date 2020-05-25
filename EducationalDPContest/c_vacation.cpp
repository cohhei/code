#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1e5;
int dp[MAX_N][3];
int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n);
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    v[i].push_back(a);
    v[i].push_back(b);
    v[i].push_back(c);
  }
  rep(i, n) rep(j, 3) rep(k, 3) { 
    if (j == k) continue;
    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + v[i][k]); 
  }
  int ans = 0;
  rep(j, 3) ans = max(ans, dp[n][j]);
  cout << ans << endl;
  return 0;
}