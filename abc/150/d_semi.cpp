#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll cnt = 0;
  sort(a.begin(), a.end());
  for (int i = 1; i * a[0] <= m * 2; i++) {
    // for (int i = 1; i <= m; i++) {
    cout << i * a[0] / 2 << endl;
    bool flg = true;
    rep(j, n) {
      if ((i * a[0] * 10 / a[j]) % 10 != 0) {
        flg = false;
        // cout << (i * a[0] / 2 * 10  a[j]) % 10 << endl;
        break;
      }
    }
    if (flg) cnt++;
  }
  cout << cnt << endl;
  return 0;
}