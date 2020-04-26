#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double dist(P p1, P p2) {
  return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
              (p1.second - p2.second) * (p1.second - p2.second));
}
int main() {
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    p[i] = P(x, y);
  }

  vector<int> idx(n);
  rep(i, n) idx[i] = i;
  double ans = 0;
  int cnt = 0;
  do {
    cnt++;
    rep(i, n - 1) ans += dist(p[idx[i]], p[idx[i + 1]]);
  } while (next_permutation(idx.begin(), idx.end()));

  ans /= cnt;
  printf("%.10lf\n", ans);
  return 0;
}