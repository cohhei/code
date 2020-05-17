#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end());

  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int r = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin();
      int l = j + 1;
      ans += max(0, r - l);
    }
  }
  cout << ans << endl;
  return 0;
}