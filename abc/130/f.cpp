#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  u--, v--;
  vector<vector<int> > to(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> dv(n, INF);
  dv[v] = 0;
  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (int next : to[from]) {
      if (dv[next] != INF) continue;
      dv[next] = dv[from] + 1;
      q.push(next);
    }
  }

  int ans = dv[u];
  vector<int> du(n, INF);
  du[u] = 0;
  q.push(u);
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    int nd = du[from] + 1;
    for (int next : to[from]) {
      if (du[next] != INF) continue;
      if (dv[next] <= nd) continue;
      ans = max(ans, dv[next]);
      // if (dv[next] == nd) continue;
      du[next] = nd;
      q.push(next);
    }
  }
  cout << ans - 1 << endl;

  return 0;
}