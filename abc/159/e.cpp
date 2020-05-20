#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
int c[10][1001];

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  int ans = INF;
  rep(div, 1 << (h - 1)) {
    int g = 0;          // group ID iterator
    vector<int> id(h);  // group ID
    rep(i, h) {
      id[i] = g;
      if (div >> i & 1) g++;
    }
    g++;

    rep(i, g) rep(j, w) c[i][j] = 0;
    rep(i, h) rep(j, w) c[id[i]][j] += (s[i][j] - '0');

    int num = g - 1;
    vector<int> now(g);
    auto add = [&](int j) {
      rep(i, g) now[i] += c[i][j];
      rep(i, g) if (now[i] > k) return false;
      return true;
    };

    rep(j, w) {
      if (!add(j)) {
        num++;
        now = vector<int>(g);
        if (!add(j)) {
          num = INF;
          break;
        }
      }
    }
    ans = min(num, ans);
  }
  cout << ans << endl;
  return 0;
}