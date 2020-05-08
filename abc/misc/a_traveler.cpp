#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1e5;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  rep(i, n - 1) cin >> s[i];
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  vector<ll> sum(n + 1);  // 累積和
  sum[0] = 0;
  rep(i, n) sum[i + 1] = (sum[i] + s[i]) % mod;

  int now = 0;
  ll ans = 0;
  rep(i, m) {
    int from = now;
    int to = now + a[i];
    if (from > to) swap(from, to);
    ans += ((sum[to] + mod) - sum[from]) % mod;
    ans %= mod;
    now += a[i];
  }
  cout << ans % mod << endl;
  return 0;
}