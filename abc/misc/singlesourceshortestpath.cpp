#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9;
const int MAX_V = 1e5;
const int MAX_E = 5e5;

// first: distance, second: ID of the point
using P = pair<int, int>;

// first: to, second: cost
vector<P> G[MAX_V];
int dist[MAX_V];

// ダイクストラ
void dijkstra(int s) {  // s: start
  priority_queue<P, vector<P>, greater<P> > q;
  dist[s] = 0;
  q.push(P(0, s));

  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      int to = G[v][i].first;
      int cost = G[v][i].second;
      if (dist[to] > dist[v] + cost) {
        dist[to] = dist[v] + cost;
        q.push(P(dist[to], to));
      }
    }
  }
}

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  rep(i, V) dist[i] = INF;
  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back(P(t, d));
    // 無向グラフの場合は両方に追加
    // G[t].push_back(P(s, d));
  }
  dijkstra(r);
  rep(i, V) {
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }
  return 0;
}