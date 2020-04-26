#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // sort(c.begin(), c.end());

  int ans = 0;
  rep(i, n) {
    int st = 0, en = n - 1;
    int bi = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
    rep(j, bi) { ans += lower_bound(a.begin(), a.end(), b[j]) - a.begin(); }
  }
  cout << ans << endl;
  return 0;
}