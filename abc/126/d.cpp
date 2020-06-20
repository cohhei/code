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
void printp(vector<P> v) {
  for (P i : v) printf("%d,%d ", i.first, i.second);
  cout << endl;
}

const int MAX_N = 1e5 + 1;
vector<P> to[MAX_N];

int main() {
  int n;
  cin >> n;
  vector<int> colors = vector<int>(n, -1);
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    to[u].push_back(P(v, w));
    to[v].push_back(P(u, w));
  }
  colors[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (P p : to[u]) {
      int v = p.first;
      int w = p.second;
      if (colors[v] != -1) continue;
      if (w % 2 == 0)
        colors[v] = colors[u];
      else
        colors[v] = (colors[u] + 1) % 2;
      q.push(v);
    }
  }
  rep(i, n) cout << colors[i] << endl;
  return 0;
}