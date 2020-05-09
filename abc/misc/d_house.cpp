#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll sum[125][125];

int main() {
  ll h, w, k, v;
  cin >> h >> w >> k >> v;
  rep(i, h) rep(j, w) {
    int a;
    cin >> a;
    sum[i][j] = a;
    if (i > 0) sum[i][j] += sum[i - 1][j];
    if (j > 0) sum[i][j] += sum[i][j - 1];
    if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
  }

  int ans = 0;
  for (int i1 = 0; i1 < h; i1++)
    for (int j1 = 0; j1 < w; j1++)
      for (int i2 = i1; i2 < h; i2++)
        for (int j2 = j1; j2 < w; j2++) {
          int s = (i2 - i1 + 1) * (j2 - j1 + 1);
          ll cost = sum[i2][j2] + k * s;
          if (i1 > 0) cost -= sum[i1 - 1][j2];
          if (j1 > 0) cost -= sum[i2][j1 - 1];
          if (i1 > 0 && j1 > 0) cost += sum[i1 - 1][j1 - 1];
          if (cost <= v) ans = max(ans, s);
        }

  cout << ans << endl;
  return 0;
}