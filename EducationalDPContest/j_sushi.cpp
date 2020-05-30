#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double dp[301][301][301];
double f(int n, int i, int j, int k) {
  if (dp[i][j][k] >= 0.0) return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0) return 0.0;

  double res = 0.0;
  if (i > 0) res += f(n, i - 1, j, k) * i;
  if (j > 0) res += f(n, i + 1, j - 1, k) * j;
  if (k > 0) res += f(n, i, j + 1, k - 1) * k;
  res += n;
  res *= 1.0 / (i + j + k);
  return dp[i][j][k] = res;
}

int main() {
  int n;
  cin >> n;
  vector<int> cnt(3);
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a - 1]++;
  }
  memset(dp, -1, sizeof(dp));
  double ans = f(n, cnt[0], cnt[1], cnt[2]);
  printf("%.10lf\n", ans);
  return 0;
}