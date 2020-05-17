#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > to(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  const int INF = 1e9;
  vector<int> dist(n, INF);
  vector<int> parent(n);
  queue<int> q;
  q.push(0);
  dist[0];
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (int t : to[from]) {
      if (dist[t] != INF) continue;
      dist[t] = dist[from] + 1;
      q.push(t);
      parent[t] = from;
    }
  }
  for (int d : dist) {
    if (d == INF) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i < n; i++) cout << parent[i] + 1 << endl;
  return 0;
}