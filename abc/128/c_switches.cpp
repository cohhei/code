#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  vector<int> p(m);
  rep(i, m) {
    int k;
    cin >> k;
    vector<int> si(k);
    rep(j, k) {
      cin >> si[j];
      si[j]--;
    }
    s[i] = si;
  }
  rep(i, m) cin >> p[i];

  int ans = 0;
  int loop = pow(2, n);
  rep(ptt, loop) {
    int on = 0;
    rep(i, m) {  // light
      int cnt = 0;
      rep(j, s[i].size()) {  // switch
        int shift = s[i][j];
        if (ptt & (1 << shift)) cnt++;
      }
      if (cnt % 2 == p[i]) on++;
    }
    if (on == m) ans++;
  }
  cout << ans << endl;
  return 0;
}