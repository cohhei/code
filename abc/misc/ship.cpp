#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9;
const int MAX_V = 1e5;

struct edge {
  int to;
  int cost;
};

// first: distance, second: ID of the point
using P = pair<int, int>;

vector<edge> G[MAX_V];
int dist[MAX_V];

void dijkstra(int s) {  // s: start
  priority_queue<P, vector<P>, greater<P> > q;
  rep(i, 101) dist[i] = INF;
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
  int n, k;
  cin >> n >> k;
  rep(i, k) {
    int ty;
    cin >> ty;
    if (ty == 0) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      dijkstra(a);
      int ans = dist[b] == INF ? -1 : dist[b];
      cout << ans << endl;
    } else {
      int c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      edge ed = {d, e};
      G[c].push_back(ed);
      ed = {c, e};
      G[d].push_back(ed);
    }
  }
  return 0;
}