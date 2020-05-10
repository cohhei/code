#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<P> a;

  rep(i, n) {
    int c;
    cin >> c;
    if (a.empty()) {
      a.push_back(P(c, 1));
      continue;
    }
    int en = a.size() - 1;
    P e = a[en];
    if (i % 2 == 0 && e.first != c) {
      a.push_back(P(c, 1));
      continue;
    }
    e.second++;
    if (i % 2 == 1) e.first = c;
    a[en] = e;

    printf("%d ", i);
    for(P p : a) printf("%d x %d ", p.first, p.second);
    cout << endl;

    if (en > 0) {
      P ee = a[en - 1];
      if (ee.first == e.first) {
        ee.second += e.second;
        a[en - 1] = ee;
        a.erase(a.end() - 1);
      }
    }
  }
  ll ans = 0;
  for (P p : a) {
    if (p.first == 0) ans += p.second;
  }
  cout << ans << endl;
  return 0;
}