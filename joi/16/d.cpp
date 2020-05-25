#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int p[110000];
int sum[20][110000];
int sz[20];

const int INF = 1e9;

int main() {
  int a, b;
  cin >> a >> b;
  rep(i, a) {
    cin >> p[i];
    p[i]--;
    sum[p[i]][i + 1]++;
    sz[p[i]]++;
  }
  rep(i, b) rep(j, a) sum[i][j + 1] += sum[i][j];
  vector<int> dp(1 << b, INF);
  dp[0] = 0;
  rep(i, 1 << b) {
    int pos = 0;
    rep(j, b) if (i >> j & 1) pos += sz[j];
    rep(j, b) {
      if (i >> j & 1) continue;
      dp[i + (1 << j)] = min(dp[i + (1 << j)],
                             dp[i] + sz[j] - sum[j][pos + sz[j]] + sum[j][pos]);
    }
  }
  cout << dp[(1 << b) - 1] << endl;
  return 0;
}