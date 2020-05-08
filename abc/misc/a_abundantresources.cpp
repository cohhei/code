#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n + 1);  // 累積和
  sum[0] = 0;
  rep(i, n) sum[i + 1] = sum[i] + a[i];

  for (int k = 1; k <= n; k++) {
    ll ans = 0;
    for (int i = 0; i + k <= n; i++) ans = max(ans, sum[i + k] - sum[i]);
    cout << ans << endl;
  }
  return 0;
}