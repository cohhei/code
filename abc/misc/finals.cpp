#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using edge = tuple<int, int, int>;  // w, s, t

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

void kruskal(int n, int k) {
  ll ans = 0;
  uf = unionFind(n);
  uf.d = vector<int>(n);
  rep(i, n) uf.d[i] = -1;
  sort(G.begin(), G.end());
  int cnt = 0;
  for (edge e : G) {
    if (cnt == n - k) break;
    int w = get<0>(e), s = get<1>(e), t = get<2>(e);
    if (!uf.same(s, t)) {
      uf.unite(s, t);
      ans += w;
      cnt++;
    }
  }
  cout << ans << endl;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  G = vector<edge>(m);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[i] = edge(c, a, b);
  }
  kruskal(n, k);
  return 0;
}