#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll l, r;
  cin >> l >> r;
  int mod = 2019;
  r = min(r, l + mod);
  ll ans = mod;
  for (ll i = l; i < r; i++) {
    for (ll j = l + 1; j <= r; j++) {
      ans = min(ans, (i * j) % mod);
    }
  }
  cout << ans << endl;
  return 0;
}