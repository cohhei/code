#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll a[100][100];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, n) rep(j, m) {
    ll aij;
    cin >> aij;
    a[i][j] = aij;
  }
  ll ans = 0;
  rep(i, m) rep(j, m) {
    if (i == j) continue;
    ll sum = 0;
    rep(k, n) { sum += max(a[k][i], a[k][j]); }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}