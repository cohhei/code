#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int D, n, m;
  cin >> D >> n >> m;
  vector<int> d(n);
  rep(i, n - 1) cin >> d[i];
  vector<int> k(m);
  rep(i, m) cin >> k[i];

  sort(d.begin(), d.end());
  d.push_back(D);
  int ans = 0;
  rep(i, m) {
    int st = 0, en = n;
    while (en - st > 1) {
      int mid = (en + st) / 2;
      if (d[mid] == k[i]) break;
      if (d[mid] > k[i])
        en = mid;
      else
        st = mid;
    }
    if (en - st == 1) ans += min(abs(d[en] - k[i]), abs(k[i] - d[st]));
  }
  cout << ans << endl;
  return 0;
}