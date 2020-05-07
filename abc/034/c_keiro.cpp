#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// べき乗
const ll mod = 1000000007;
ll p(ll a, ll n) {  // a^n
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

const int MAX_N = 2e5;
ll fac[MAX_N];

int main() {
  fac[0] = 1;
  rep(i, MAX_N) fac[i + 1] = (fac[i] * (i + 1)) % mod;

  int w, h;
  cin >> w >> h;

  // (H + W -2)! / (H-1)! (W-1)!
  // modの値で割るにはmod-2乗したものをかける
  ll ans = fac[h + w - 2] % mod;
  ans = ans * p(fac[w - 1], mod - 2) % mod;
  ans = ans * p(fac[h - 1], mod - 2) % mod;
  cout << ans << endl;
  return 0;
}