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

int main() {
  int n, k;
  cin >> n >> k;

  // 重複組合せ nHk = n-1+kCn-1
  ll ans = choose(n - 1 + k, n - 1) % mod;
  cout << ans << endl;
  return 0;
}