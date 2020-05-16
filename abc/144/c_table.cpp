#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;

  ll rn = sqrtl(n);
  ll ans = 1e18;
  for (int i = 1; i <= rn; i++) {
    if (n % i != 0) continue;
    ll c = i + n / i - 2;
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;
}