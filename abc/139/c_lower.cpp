#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int ans = 0, cnt = 0, now = h[0];
  for (int i = 1; i < n; i++) {
    if (now < h[i]) {
      ans = max(ans, cnt);
      cnt = 0;
    } else {
      cnt++;
    }
    now = h[i];
  }
  ans = max(ans, cnt);
  cout << ans << endl;
  return 0;
}