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

int dp[100005][2];

int main() {
  string s;
  cin >> s;
  dp[0][0] = 1;
  int n = s.size();
  rep(i, n) {
    {
      if (s[i] == '0') {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
      } else {
        dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
      }
    }
    {
      if (s[i] == '0') {
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      } else {
        (dp[i + 1][0] += dp[i][0] * 2 % mod) %= mod;
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      }
    }
  }
  int ans = (dp[n][0] + dp[n][1]) % mod;
  cout << ans << endl;
  return 0;
}