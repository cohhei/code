#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n >> d;
  int x[11][11];
  rep(i, n) rep(j, d) cin >> x[i][j];
  int ans = 0;
  rep(i, n) for (int j = i + 1; j < n; j++) {
    ll dist = 0;
    rep(k, d) dist += abs(x[i][k] - x[j][k]) * abs(x[i][k] - x[j][k]);
    double dbl = sqrt(dist);
    if (int(dbl) == dbl) ans++;
  }
  cout << ans << endl;
  return 0;
}