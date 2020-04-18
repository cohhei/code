#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// RE and TLE
int bod_main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  // sort(a.rbegin(), a.rend());
  vector<int> p(n);
  rep(i, n) {
    rep(j, n) { p.push_back(a[i] + a[j]); }
  }
  sort(p.rbegin(), p.rend());

  ll ans = 0;
  rep(i, m) ans += p[i];
  cout << ans << endl;
  return 0;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> s(n + 1);  // 累積和
  rep(i, n) s[i + 1] = s[i] + a[i];

  // a内の値がx以上の要素の合計と個数
  auto calc = [&](int x) {
    ll tot = 0, num = 0;
    rep(i, n) {
      int j = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
      num += n - j;
      tot += s[n] - s[j];
      tot += a[i] * ll(n - j);
    }
    return make_pair(tot, num);
  };

  int l = 0, r = 200001;
  while (l + 1 < r) {
    int c = (l + r) >> 1;
    if (calc(c).second >= m)
      l = c;
    else
      r = c;
  }
  auto p = calc(l);
  ll ans = p.first;
  ans -= (p.second - m) * l;
  cout << ans << endl;
  return 0;
}