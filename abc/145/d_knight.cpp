#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1e9 + 7;
ll p(ll a, ll n) {  // a^n
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll choose(ll n, ll a) {
  ll x = 1, y = 1;
  rep(i, a) {
    x *= n - i;
    x %= mod;
    y *= i + 1;
    y %= mod;
  }
  return x * p(y, mod - 2);
}

const int MAX_N = 2e6;
ll fac[MAX_N];

int main() {
  fac[0] = 1;
  rep(i, MAX_N) fac[i + 1] = (fac[i] * (i + 1)) % mod;

  int x, y;
  cin >> x >> y;

  if ((x + y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll n = (2 * x - y) / 3;
  ll m = (2 * y - x) / 3;
  if (n < 0 || m < 0) {
    cout << 0 << endl;
    return 0;
  }
  n %= mod;
  m %= mod;
  ll ans = choose(n + m, n) % mod;
  cout << ans << endl;

  return 0;
}