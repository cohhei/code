#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll lp = 1 << n;
  ll ans = 112345678901;
  rep(ptn, lp) {
    int cnt = 0;
    rep(i, n - 1) if (ptn & 1 << i) cnt++;
    if (cnt < k - 1) continue;

    ll height = a[0];
    ll sum = 0;
    rep(i, n) {
      if (ptn & 1 << i) {
        if (height >= a[i + 1]) sum += height - a[i + 1] + 1;
        height = max(a[i + 1], height + 1);
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}