#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  n++;
  vector<int> p(n);
  p[0] = 0;  // 投げないパターンを0点の場合と考える
  for (int i = 1; i < n; i++) cin >> p[i];

  // 2本のパターンをすべて網羅
  int nn = n * n;
  vector<int> q(nn);
  rep(i, n) rep(j, n) q[i * n + j] = p[i] + p[j];
  sort(q.begin(), q.end());

  int ans = 0;
  // qの中からもう一度最適なqを選ぶ
  // 二分探索
  rep(i, nn) {
    if (q[i] > m) continue;
    int j = lower_bound(q.begin(), q.end(), m - q[i]) - q.begin() - 1;
    ans = max(ans, q[i] + q[j]);
  }
  cout << ans << endl;
  return 0;
}