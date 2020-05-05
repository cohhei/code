#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9;
const int MAX_V = 1e5;
const int MAX_E = 5e5;

struct edge {
  int to;
  int cost;
};

// first: distance, second: ID of the point
using P = pair<int, int>;

vector<edge> G[MAX_V];
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
      edge e = G[v][i];
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        q.push(P(dist[e.to], e.to));
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
    edge e = {t, d};
    G[s].push_back(e);
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