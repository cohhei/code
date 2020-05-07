#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using edge = tuple<double, int, int>;  // w, s, t

struct unionFind {
  vector<int> d;  // 根： 木のサイズ x -1, それ以外： 親のID
  unionFind(int n = 0) : d(n, -1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    // root化しておく
    x = find(x);
    y = find(y);
    if (x == y) return false;

    // x を y に unite
    // d[x] のほうが多きい（=サイズが小さい）場合はswap
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
} uf;

vector<edge> G;
int V;

void kruskal() {
  double ans = 0;
  sort(G.begin(), G.end());
  for (edge e : G) {
    double w = get<0>(e);
    int s = get<1>(e), t = get<2>(e);
    if (!uf.same(s, t)) {
      uf.unite(s, t);
      ans += w;
    }
  }
  printf("%.3lf\n", ans);
}

int main() {
  while (1) {
    cin >> V;
    if (V == 0) break;
    vector<double> x(V);
    vector<double> y(V);
    vector<double> z(V);
    vector<double> r(V);
    rep(i, V) cin >> x[i] >> y[i] >> z[i] >> r[i];

    uf = unionFind(V);
    rep(i, V) uf.d[i] = -1;
    G = vector<edge>();
    rep(i, V) rep(j, V) {
      if (i == j) continue;
      double dist =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) +
               (z[i] - z[j]) * (z[i] - z[j])) -
          (r[i] + r[j]);

      // 触れていない場合は廊下を作る
      // あとでkruskalで間引く
      // 触れいているときはすでにつながっていると考える
      if (dist > 0.0)
        G.push_back(edge(dist, i, j));
      else
        uf.unite(i, j);
    }
    kruskal();
  }
  return 0;
}