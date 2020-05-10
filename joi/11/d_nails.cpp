#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int MAX_N = 5e3 + 5;
ll sum[MAX_N][MAX_N];

int main() {
  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int a, b, x;
    cin >> a >> b >> x;
    a--;
    b--;
    sum[a][b]++;
    sum[a + x + 1][b]--;
    sum[a][b + 1]--;
    sum[a + x + 2][b + x + 2]--;
    sum[a + x + 1][b + x + 2]++;
    sum[a + x + 2][b + 1]++;
  }
  rep(i, n) rep(j, n) sum[i][j + 1] += sum[i][j];
  rep(i, n) rep(j, n) sum[i + 1][j] += sum[i][j];
  rep(i, n) rep(j, n) sum[i + 1][j + 1] += sum[i][j];

  ll ans = 0;
  rep(i, n) rep(j, n) {
    if (sum[i][j] > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}