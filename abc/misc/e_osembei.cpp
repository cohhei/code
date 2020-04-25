#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> a(c, vector<int>(r));
  rep(i, r) rep(j, c) cin >> a[j][i];

  int lp = pow(2, r);
  int ans = 0;
  rep(ptn, lp) {
    int ans_t = 0;
    rep(i, c) {  // column
      int cnt = 0;
      rep(j, r) {  // row
        if (a[i][j] == (ptn & 1 << j) >> j) cnt++;
      }
      ans_t += max(cnt, r - cnt);
    }
    ans = max(ans, ans_t);
  }

  cout << ans << endl;
  return 0;
}