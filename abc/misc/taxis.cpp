#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9 + 1;
const int MAX_N = 5e3;

// first: distance, second: ID of the point
using P = pair<int, int>;

vector<int> G[MAX_N];
vector<int> H[MAX_N];
int R[MAX_N], C[MAX_N];
int costs[MAX_N];
int N, K;

void bfs(int s) {
  int dist[MAX_N];
  rep(i, N) dist[i] = INF;
  queue<int> que;
  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int to : G[v]) {
      if (dist[to] > dist[v] + 1) {
        dist[to] = dist[v] + 1;
        que.push(to);
        if (dist[to] <= R[s]) H[s].push_back(to);
      }
    }
  }
}

void dijkstra(int s) {
  rep(i, MAX_N) costs[i] = INF;
  priority_queue<P, vector<P>, greater<P> > que;
  costs[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P top = que.top();
    que.pop();
    int from = top.second;
    for (int to : G[from]) {
      ll cost = C[from];
      if (costs[to] > costs[from] + cost) {
        costs[to] = costs[from] + cost;
        que.push(P(costs[to], to));
      }
    }
  }
}

int main() {
  cin >> N >> K;
  rep(i, N) cin >> C[i] >> R[i];

  rep(i, K) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, N) bfs(i);
  rep(i, N) G[i].insert(G[i].end(), H[i].begin(), H[i].end());

  dijkstra(0);
  cout << costs[N - 1] << endl;
  return 0;
}