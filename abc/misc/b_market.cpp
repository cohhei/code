#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll p[30][2];
int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> p[i][0] >> p[i][1];
  ll ans = 1001001001001;
  rep(i, n) {
    rep(j, n) {
      rep(s, 2) rep(g, 2) {
        ll start = p[i][s], goal = p[j][g];
        if (start > goal) swap(start, goal);
        ll dist = goal - start;
        ll sum = 0;
        rep(k, n) {
          sum += dist;
          if (p[k][0] < start) sum += abs(start - p[k][0]) * 2;
          if (p[k][1] > goal) sum += abs(p[k][1] - goal) * 2;
        }
        ans = min(ans, sum);
      }
    }
  }
  cout << ans << endl;
  return 0;
}