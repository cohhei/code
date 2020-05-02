#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 20001;
const int MAX_M = 17;
unsigned int dp[MAX_N][MAX_M];

int round(int x) { return min(255, max(0, x)); }
int main() {
  while (1) {
    int n, m;
    cin >> n >> m;
    if (n + m == 0) return 0;

    vector<int> c(m);
    rep(i, m) cin >> c[i];
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> y(n);
    y[0] = 128;

    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    // int y = 128;
    rep(i, n + 1) rep(j, m) {
      y[i + 1] = round(y[i] + c[j]);
      int diff = abs(x[i] - y[i + 1]);
      rep(k, m) {
        y[i + 2] = round(y[i + 1] + c[k]);
        diff += abs(x[i + 1] - y[i + 2]);
        // printf("xn: %d x: %d c: %d diff: %d\n", x[i + 1], x[i], c[j], diff);
        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + diff * diff);
      }
    }

    rep(j, m) printf("%5d", c[j]);
    cout << endl;
    rep(i, n + 1) {
      rep(j, m) printf("%5d", dp[i][j]);
      cout << endl;
    }
  }
  return 0;
}