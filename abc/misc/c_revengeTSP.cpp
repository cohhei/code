#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 15;
ll dist[MAX_N][MAX_N];  // dist[i][j] i から j への距離
ll t[MAX_N][MAX_N];  // time[i][j] i から j への道の封鎖時刻

// dp[i][j]: 状態iでjにいるときの最短経路
// 状態iはビットで管理: 00011->点0と点1は通貨済
int dp[1 << MAX_N][MAX_N];
int n, m;
const ll inf = 1001001001001;

// 巡回セールスマン問題に時間制限
// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
// とけてない
int dfs(int s, int v, ll now) {
  if (dp[s][v] >= 0) return dp[s][v];
  if (s == (1 << n) - 1 && v == 0) return dp[s][v] = 0;

  ll ans = inf;
  rep(u, n) {
    if (t[v][u] <= now) continue;
    // uに行ったことがない場合
    if (!(s >> u & 1)) ans = min(ans, dfs(s | 1 << u, u, now + 1) + dist[v][u]);
  }

  return dp[s][v] = ans;
}

int main() {
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  // パスがない場合は距離がinfになる
  fill(dist[0], dist[0] + MAX_N * MAX_N, inf);

  rep(i, m) {
    int f, t, c;
    cin >> f >> t >> c;
    dist[f][t] = c;
  }
  ll ans = dfs(0, 0, 0);
  ans = ans == inf ? -1 : ans;
  cout << ans << endl;
  return 0;
}