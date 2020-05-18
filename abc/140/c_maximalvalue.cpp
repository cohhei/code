#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n - 1) cin >> b[i];
  vector<int> a(n);
  a[0] = b[0];
  for (int i = 1; i < n; i++) {
    a[i] = b[i - 1];
    if (i < n - 1) a[i] = min(a[i], b[i]);
  }
  int ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;
  return 0;
}