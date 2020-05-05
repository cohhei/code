#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1e9 + 1;
const int MAX_N = 1e5 + 1;

// first: distance, second: ID of the point
using P = pair<int, int>;

vector<int> G[MAX_N];
ll costs[MAX_N];
int dist[MAX_N];  // distance from zombie cyties
int p, Q, S;
int N, M, K;

void bfs(int s) {
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
      if (dist[to] == 0) continue;
      ll cost = dist[to] <= S ? Q : p;
      if (costs[to] > costs[from] + cost) {
        costs[to] = costs[from] + cost;
        que.push(P(costs[to], to));
      }
    }
  }
}

int main() {
  cin >> N >> M >> K >> S;
  cin >> p >> Q;

  vector<int> zombie(K);  // zombie cities
  rep(i, K) {
    cin >> zombie[i];
    zombie[i]--;
  }
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(i, N) dist[i] = INF;
  rep(i, K) bfs(zombie[i]);
  // cout << "dist" << endl;
  // rep(i, n) printf("%d %lld\n", i + 1, dist[i]);

  dijkstra(0);
  // cout << "costs" << endl;
  // rep(i, n) printf("%d %lld\n", i + 1, costs[i]);
  ll ans = costs[N - 1];
  if (dist[N - 1] > S)
    ans -= p;
  else
    ans -= Q;
  cout << ans << endl;
  return 0;
}