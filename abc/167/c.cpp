#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[12][12];
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  ll inf = 2e6;
  ll ans = -1;
  rep(i, 1 << n) {
    vector<int> und(m);
    ll mon = 0;
    rep(j, n) {
      if (i & 1 << j) {
        rep(k, m) und[k] += a[j][k];
        mon += c[j];
      }
    }
    bool flg = true;
    rep(j, m) {
      if (und[j] < x) flg = false;
    }

    if (flg) {
      if (ans == -1)
        ans = mon;
      else
        ans = min(ans, mon);
    }
  }
  cout << ans << endl;

  return 0;
}