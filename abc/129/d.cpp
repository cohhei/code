#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> m(h);
  rep(i, h) cin >> m[i];

  vector<vector<int> > width(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) {
      if (m[i][j] == '#') continue;
      width[i][j] = 1;
      if (j > 0) width[i][j] += width[i][j - 1];
    }
    for (int j = w - 1; j > 0; j--) {
      if (m[i][j - 1] == '#' || m[i][j] == '#') continue;
      width[i][j - 1] = width[i][j];
    }
  }

  vector<vector<int> > height(h, vector<int>(w));
  rep(j, w) {
    rep(i, h) {
      if (m[i][j] == '#') continue;
      height[i][j] = 1;
      if (i > 0) height[i][j] += height[i - 1][j];
    }
    for (int i = h - 1; i > 0; i--) {
      if (m[i - 1][j] == '#' || m[i][j] == '#') continue;
      height[i - 1][j] = height[i][j];
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, height[i][j] + width[i][j] - 1);

  cout << ans << endl;
  return 0;
}