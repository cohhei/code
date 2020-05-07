#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll cost[120002];  // distance from 0

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

ll calc_total_cost(int from, int to) {
  if (from > to) swap(from, to);
  return (cost[to] + mod - cost[from]) % mod;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<int> c(q + 2);
  c[0] = 0;
  c[q] = 0;
  rep(i, q) {
    cin >> c[i + 1];
    c[i + 1]--;
  }

  cost[0] = 0;
  rep(i, n) cost[i + 1] = (cost[i] + p(a[i], a[i + 1])) % mod;

  ll ans = 0;
  rep(i, q + 1) ans = (ans + calc_total_cost(c[i], c[i + 1])) % mod;
  cout << ans << endl;
  return 0;
}