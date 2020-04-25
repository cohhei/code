// bit ビット全探索
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  map<P, bool> mp;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    mp[P(x, y)] = true;
  }

  int lp = pow(2, n);
  int ans = 0;
  rep(ptn, lp) {
    vector<int> vec;
    rep(i, n) if (ptn & 1 << i) vec.push_back(i);
    bool flg = true;
    int sz = vec.size();
    rep(i, sz) {
      for (int j = i + 1; j < sz; j++) {
        if (!mp[P(vec[i], vec[j])]) {
          flg = false;
          break;
        }
      }
    }
    if (flg) ans = max(ans, sz);
  }
  cout << ans << endl;
  return 0;
}