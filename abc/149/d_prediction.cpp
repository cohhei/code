#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, r, s, p;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  ll ans = 0;
  map<char, int> v;
  v['r'] = p;
  v['s'] = r;
  v['p'] = s;
  vector<bool> win(n, true);
  rep(i, k) ans += v[t[i]];

  for (int i = k; i < n; i++) {
    if (t[i] != t[i - k] || !win[i - k])
      ans += v[t[i]];
    else
      win[i] = false;
  }
  cout << ans << endl;
  return 0;
}