#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

// square869120Contest #1 G - Revenge of Traveling Salesman Problem
// 巡回セールスマン問題リベンジ
// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
// bit dp ビットDP
struct edge {
  int to;
  ll dist;
  ll time;
};

const ll INF = 1e18;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<edge> > to(n);
  rep(i, m) {
    int s, t;
    ll d, tm;
    cin >> s >> t >> d >> tm;
    s--, t--;
    to[s].push_back((edge){t, d, tm});
    to[t].push_back((edge){s, d, tm});
  }

  // dp[i][j]: ビットパターンiに通過済で現在jにいるとき
  // first: 最短距離, second: 最短経路のパターン
  vector<vector<P> > dp(1 << n, vector<P>(n, P(INF, 0)));
  dp[0][0] = P(0, 1);

  rep(passed, 1 << n) {  // 通過済みの建物
    rep(i, n) {          // 現在地
      for (edge e : to[i]) {
        ll next = passed | (1 << e.to);          // 次の状態
        ll cost = dp[passed][i].first + e.dist;  // 遷移する場合のコスト
        if (next == passed) continue;            // 通貨済みの場合
        if (cost > e.time) continue;             // 時間切れでの場合
        if (dp[next][e.to].first < cost) continue;  // 最短ではない場合
        if (dp[next][e.to].first == cost)
          dp[next][e.to].second += dp[passed][i].second;
        else
          dp[next][e.to].second = dp[passed][i].second;
        dp[next][e.to].first = cost;
      }
    }
  }

  P ans = dp[(1 << n) - 1][0];
  if (ans.first == INF)
    cout << "IMPOSSIBLE" << endl;
  else
    printf("%lld %lld\n", ans.first, ans.second);
  return 0;
}