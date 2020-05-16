#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1001002003004005006ll;

// とけてない
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  ll ans = INF;
  rep(ptn, 1 << n) {
    if (__builtin_popcount(ptn) > k) continue;
    int now = 0;
    ll cnt = 0;
    rep(i, n) {
      if (ptn & 1 << i) continue;
      if (h[i] > now) cnt += h[i] - now;
      now = h[i];
    }
    ans = min(ans, cnt);
  }
  ans = max(1ll, ans);
  cout << ans << endl;
  return 0;
}