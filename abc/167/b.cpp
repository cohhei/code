#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k < a) {
    cout << k << endl;
    return 0;
  }
  ll ans = 0;
  ans += a;
  k -= a + b;
  if (k <= 0) {
    cout << ans << endl;
    return 0;
  }
  ans -= k;
  cout << ans << endl;
  return 0;
}