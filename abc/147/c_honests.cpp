#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> g(15, vector<int>(15, -1));

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int m;
    cin >> m;
    rep(j, m) {
      int x, y;
      cin >> x >> y;
      g[i][x - 1] = y;
    }
  }

  int ans = 0;
  rep(i, 1 << n) {
    vector<int> d(n);
    rep(j, n) if (i&1<<j) d[j] = 1;
    bool ok = true;
    rep(j, n) {
      if (!d[j]) continue;
      rep(k, n) {
        if (g[j][k] == -1) continue;
        if (g[j][k] != d[k]) ok = false;
      }
    }
    if (ok) ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
  return 0;
}