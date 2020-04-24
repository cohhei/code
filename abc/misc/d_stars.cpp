#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int m;
  cin >> m;
  vector<P> ps(m);
  rep(i, m) cin >> ps[i].first >> ps[i].second;
  int n;
  cin >> n;
  vector<P> stars;
  map<P, bool> check;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    stars.push_back(P(x, y));
    check[P(x, y)] = true;
  }

  for (P s : stars) {
    int sx = s.first, sy = s.second;
    int dx = s.first - ps[0].first;
    int dy = s.second - ps[0].second;
    bool flag = true;
    for (P p : ps) {
      P pp = P(p.first + dx, p.second + dy);
      if (!check[pp]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d %d\n", dx, dy);
    }
  }
  return 0;
}