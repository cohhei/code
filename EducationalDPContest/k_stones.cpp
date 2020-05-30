#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  bool dp[k + 1];
  rep(i, k + 1) dp[i] = false;

  rep(i, k) rep(j, n) {
    if (i + 1 >= a[j]) dp[i + 1] |= !dp[i + 1 - a[j]];
  }

  if (dp[k])
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  return 0;
}