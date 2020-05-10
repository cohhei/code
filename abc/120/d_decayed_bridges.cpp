#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

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
};

ll combi(ll n) { return n * (n - 1) / 2; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  rep(i, m) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  vector<ll> ans(m);
  unionFind uf = unionFind(n);
  ll sum = combi(n);
  for (int i = m - 1; i >= 0; i--) {
    ans[i] = sum;
    ll bx = combi(uf.size(x[i]));
    ll by = combi(uf.size(y[i]));
    if (uf.unite(x[i], y[i])) sum -= combi(uf.size(x[i])) - bx - by;
  }
  rep(i, m) cout << ans[i] << endl;
  return 0;
}