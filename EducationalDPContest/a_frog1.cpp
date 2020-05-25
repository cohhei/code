#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<int> dp(n);
  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);
  rep(i, n - 2) {
    ll a = abs(h[i] - h[i + 2]) + dp[i];
    ll b = abs(h[i + 1] - h[i + 2]) + dp[i + 1];
    dp[i + 2] = min(a, b);
  }
  cout << dp[n - 1] << endl;
  return 0;
}