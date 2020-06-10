#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  map<int, bool> broken;
  rep(i, m) {
    int a;
    cin >> a;
    broken[a] = true;
  }

  vector<ll> dp(n + 1);
  dp[0] = 1;
  if (!broken[1]) dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (broken[i]) continue;
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    // dp[i] %= mod;
  }

  cout << dp[n] << endl;
  return 0;
}